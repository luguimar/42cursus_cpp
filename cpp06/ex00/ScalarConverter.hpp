#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <string>


class ScalarConverter {
    private:

        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();


        static bool isCharLiteral(const std::string& s);
        static bool isIntLiteral(const std::string& s);
        static bool isFloatLiteral(const std::string& s); // with trailing 'f' or pseudo-literals
        static bool isDoubleLiteral(const std::string& s); // or pseudo-literals


        static void fromChar(char c);
        static void fromInt(long n);
        static void fromFloat(float f);
        static void fromDouble(double d);


    public:
        static void convert(const std::string& s);
};


#endif
