#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& o): _db(o._db) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
    if (this != &o) _db = o._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

static bool splitOnce(const std::string& s, char sep, std::string& left, std::string& right) {
    std::string::size_type p = s.find(sep);
    if (p == std::string::npos) return false;
    left = s.substr(0, p);
    right = s.substr(p + 1);
    return true;
}

std::string BitcoinExchange::trim(const std::string& s) {
    std::string::size_type i = 0, j = s.size();
    while (i < j && std::isspace(static_cast<unsigned char>(s[i]))) ++i;
    while (j > i && std::isspace(static_cast<unsigned char>(s[j-1]))) --j;
    return s.substr(i, j - i);
}

bool BitcoinExchange::isLeap(int y) {
    return (y%4==0 && y%100!=0) || (y%400==0);
}

bool BitcoinExchange::isValidDate(const std::string& d) {
    // Expecta "YYYY-MM-DD"
    if (d.size() != 10 || d[4] != '-' || d[7] != '-') return false;
    for (size_t i = 0; i < d.size(); ++i) {
        if (i==4 || i==7) continue;
        if (!std::isdigit(static_cast<unsigned char>(d[i]))) return false;
    }
    int y = std::atoi(d.substr(0,4).c_str());
    int m = std::atoi(d.substr(5,2).c_str());
    int day = std::atoi(d.substr(8,2).c_str());
    if (m < 1 || m > 12) return false;
    int mdays[] = {31, (isLeap(y)?29:28), 31,30,31,30,31,31,30,31,30,31};
    int dm = mdays[m-1];
    if (day < 1 || day > dm) return false;
    return true;
}

double BitcoinExchange::parseDouble(const std::string& s, bool& ok) {
    ok = false;
    std::istringstream iss(s);
    double v;
    iss >> v;
    if (!iss.fail() && iss.eof()) { ok = true; return v; }
    return 0.0;
}

void BitcoinExchange::loadDatabase(const std::string& csvPath) {
    std::ifstream f(csvPath.c_str());
    if (!f) {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    // optional header "date,exchange_rate"
    if (std::getline(f, line)) {
        if (line.find(',') == std::string::npos || line.substr(0,4) != "date")
            ; // maybe the first line is already data; handle by processing it below
        else line.clear(); // skip header by clearing line
    }
    if (!line.empty()) {
        // process first line as data
        std::string d, p;
        if (splitOnce(line, ',', d, p)) {
            d = trim(d); p = trim(p);
            bool ok; double rate = parseDouble(p, ok);
            if (ok && isValidDate(d)) _db[d] = rate;
        }
    }
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::string d, p;
        if (!splitOnce(line, ',', d, p)) continue;
        d = trim(d); p = trim(p);
        bool ok; double rate = parseDouble(p, ok);
        if (ok && isValidDate(d)) _db[d] = rate;
    }
    if (_db.empty()) throw std::runtime_error("Error: empty/invalid database.");
}

std::map<std::string,double>::const_iterator
BitcoinExchange::findRateOnOrBefore(const std::string& date) const {
    // lower_bound: first key not less than date.
    std::map<std::string,double>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end()) {
        if (_db.empty()) return _db.end();
        // last element is <= date
        --it;
        return it->first <= date ? it : _db.end();
    }
    if (it->first == date) return it;
    if (it == _db.begin()) return _db.end(); // every key > date
    --it; // previous key < date
    return it;
}

void BitcoinExchange::processInput(const std::string& inputPath) const {
    std::ifstream f(inputPath.c_str());
    if (!f) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    // optional header "date | value"
    if (std::getline(f, line)) {
        // process only if it doesn't look like header
        if (line.find('|') == std::string::npos || line.substr(0,4) != "date") {
            // handle line
            f.seekg(0);
        }
    } else return;

    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::string left, right;
        // expected "date | value"
        std::string::size_type bar = line.find('|');
        if (bar == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        left = trim(line.substr(0, bar));
        right = trim(line.substr(bar + 1));
        if (!right.empty() && right[0] == '|') right = trim(right.substr(1));
        if (!isValidDate(left)) {
            std::cerr << "Error: bad input => " << left << std::endl;
            continue;
        }
        bool ok;
        double v = parseDouble(right, ok);
        if (!ok) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (v < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (v > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string,double>::const_iterator it = findRateOnOrBefore(left);
        if (it == _db.end()) {
            std::cerr << "Error: no rate available on or before " << left << std::endl;
            continue;
        }
        double result = v * it->second;
        std::cout << left << " => " << v << " = " << result << std::endl;
    }
}
