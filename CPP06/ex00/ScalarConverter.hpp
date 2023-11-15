#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <string>

enum scalar_types
{
    SCALAR_CHAR = 0,
    SCALAR_INT,
    SCALAR_FLOAT,
    SCALAR_DOUBLE,
    SCALAR_NONE
};
class ScalarConverter
{
  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &orig);
    ScalarConverter &operator=(const ScalarConverter &orig);
    // For OCF. But doesn't make sence...

    static std::string _literal;
    static int _type;
    static long double _actual; // converted from string to actual type value

    static void detectType(void);

    static void checkIfTypeChar(void);
    static void checkIfTypeInt(void);
    static void checkIfTypeFloat(void);
    static void checkIfTypeDouble(void);

    static void printToChar(void);
    static void printToInt(void);
    static void printToFloat(void);
    static void printToDouble(void);

    static char actualToChar(void);
    static int actualToInt(void);
    static float actualToFloat(void);
    static double actualToDouble(void);

  public:
    static void convert(std::string &literal);
    static void printDetectedResult(void);
    class DoesNotBelongAnyTypesException : public std::exception
    {
        const char *what(void) const throw();
    };

    class TooLargeValueToDisplayException : public std::exception
    {
        const char *what(void) const throw();
    };
  
};

#endif
