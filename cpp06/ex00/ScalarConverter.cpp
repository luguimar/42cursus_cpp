#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>


static bool isPseudoFloat(const std::string& s) {
    return s == "nanf" || s == "+inff" || s == "-inff";
}


static bool isPseudoDouble(const std::string& s) {
    return s == "nan" || s == "+inf" || s == "-inf";
}


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}


bool ScalarConverter::isCharLiteral(const std::string& s) {
    // Accept a single non-digit character (without quotes) as in many 42 test sets
    return s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}


bool ScalarConverter::isIntLiteral(const std::string& s) {
    if (s.empty()) return false;
        std::size_t i = 0;
    if (s[i] == '+' || s[i] == '-') ++i;
    if (i >= s.size()) return false;
    for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
        return true;
}


bool ScalarConverter::isFloatLiteral(const std::string& s) {
    if (isPseudoFloat(s)) return true;
    if (s.size() < 2 || s[s.size()-1] != 'f') return false;
    std::string core = s.substr(0, s.size()-1);
    bool dot = false; std::size_t i = 0;
    if (core[i] == '+' || core[i] == '-') ++i;
    bool hasDigit = false;
    for (; i < core.size(); ++i) {
        if (core[i] == '.') {
            if (dot) return false; dot = true; continue;
        }
        if (!std::isdigit(static_cast<unsigned char>(core[i]))) return false;
        hasDigit = true;
    }
    return hasDigit; // at least one digit overall
}


bool ScalarConverter::isDoubleLiteral(const std::string& s) {
    if (isPseudoDouble(s)) return true;
    std::size_t i = 0;
    if (s[i] == '+' || s[i] == '-') ++i;
    bool dot = false; bool hasDigit = false;
    for (; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (dot) return false; dot = true; continue;
        }
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
        hasDigit = true;
    }
    return hasDigit;
}


static void printCharFromLong(long n) {
    if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible\n";
    } else {
    char c = static_cast<char>(n);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    }
}


static void printIntFromLong(long n) {
    if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(n) << "\n";
}


static void printFloat(double v) {
    float f = static_cast<float>(v);
    if (std::isnan(v)) {
        std::cout << "float: nanf\n";
    } else if (std::isinf(v)) {
        std::cout << "float: " << (v > 0 ? "+inff" : "-inff") << "\n";
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << 'f' << "\n";
    }
}


static void printDouble(double v) {
    if (std::isnan(v)) {
        std::cout << "double: nan\n";
    } else if (std::isinf(v)) {
        std::cout << "double: " << (v > 0 ? "+inf" : "-inf") << "\n";
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << v << "\n";
    }
}


void ScalarConverter::fromChar(char c) {
    // char
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";


    // int
    std::cout << "int: " << static_cast<int>(c) << "\n";


    // float / double
    printFloat(static_cast<double>(c));
    printDouble(static_cast<double>(c));
}


void ScalarConverter::fromInt(long n) {
    printCharFromLong(n);
    printIntFromLong(n);
    printFloat(static_cast<double>(n));
    printDouble(static_cast<double>(n));
}


void ScalarConverter::fromFloat(float f) {
    // char
    if (std::isnan(f) || std::isinf(f)) std::cout << "char: impossible\n";
    else if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max()) std::cout << "char: impossible\n";
    else {
        char c = static_cast<char>(f);
        if (std::isprint(static_cast<unsigned char>(c))) std::cout << "char: '" << c << "'\n";
        else std::cout << "char: Non displayable\n";
    }


    // int
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(f) << "\n";


    // float/double
    printFloat(static_cast<double>(f));
    printDouble(static_cast<double>(f));
}


void ScalarConverter::fromDouble(double d) {
    // char
    if (std::isnan(d) || std::isinf(d)) std::cout << "char: impossible\n";
    else if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) std::cout << "char: impossible\n";
    else {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c))) std::cout << "char: '" << c << "'\n";
        else std::cout << "char: Non displayable\n";
    }


    // int
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";


    // float/double
    printFloat(d);
    printDouble(d);
}


void ScalarConverter::convert(const std::string& s) {
    if (isCharLiteral(s)) {
        fromChar(s[0]);
        return;
    }
    if (isIntLiteral(s)) {
        // use strtol to detect overflow precisely
        char *end = 0; long v = std::strtol(s.c_str(), &end, 10);
        (void)end; // we already validated format
        fromInt(v);
        return;
    }
    if (isFloatLiteral(s)) {
        if (isPseudoFloat(s)) {
            if (s == "nanf") { printCharFromLong(0); std::cout << "int: impossible\n"; std::cout << "float: nanf\n"; std::cout << "double: nan\n"; return; }
            if (s == "+inff") { printCharFromLong(0); std::cout << "int: impossible\n"; std::cout << "float: +inff\n"; std::cout << "double: +inf\n"; return; }
            if (s == "-inff") { printCharFromLong(0); std::cout << "int: impossible\n"; std::cout << "float: -inff\n"; std::cout << "double: -inf\n"; return; }
        }
        float f = static_cast<float>(std::strtod(s.c_str(), 0));
        fromFloat(f);
        return;
    }
    if (isDoubleLiteral(s)) {
        if (isPseudoDouble(s)) {
            printCharFromLong(0); std::cout << "int: impossible\n"; std::cout << "float: " << (s=="+inf"?"+inff":(s=="-inf"?"-inff":"nanf")) << "\n"; std::cout << "double: " << s << "\n"; return;
        }
        double d = std::strtod(s.c_str(), 0);
        fromDouble(d);
        return;
    }
    // Not a recognized literal
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

