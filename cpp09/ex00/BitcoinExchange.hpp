#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Carrega a DB oficial (data.csv) com "date,price"
    void loadDatabase(const std::string& csvPath);

    // Processa o ficheiro de input "date | value" e escreve no stdout
    void processInput(const std::string& inputPath) const;

private:
    std::map<std::string, double> _db; // chave: "YYYY-MM-DD"

    static bool   isValidDate(const std::string& d);
    static bool   isLeap(int y);
    static double parseDouble(const std::string& s, bool& ok);
    static std::string trim(const std::string& s);

    // devolve iterador para <= date (lower neighbor). Se nenhum <=, end()
    std::map<std::string,double>::const_iterator findRateOnOrBefore(const std::string& date) const;
};

#endif
