#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

std::string ScalarConverter::_literal;
int ScalarConverter::_type;
long double ScalarConverter::_actual;

char ScalarConverter::actualToChar(void)
{
    return (static_cast<char>(_actual));
}

int ScalarConverter::actualToInt(void)
{
    return (static_cast<int>(_actual));
}

float ScalarConverter::actualToFloat(void)
{
    return (static_cast<float>(_actual));
}

double ScalarConverter::actualToDouble(void)
{
    return (static_cast<double>(_actual));
}

void ScalarConverter::checkIfTypeChar(void)
{
    if (_literal.length() == 1 || (_literal.length() == 3 && _literal[0] == '\'' && _literal[2] == '\''))
    {
        _type = SCALAR_CHAR;
        if (_literal.length() == 1)
            _actual = _literal[0];
        else
            _actual = _literal[1];
        return;
    }
}

void ScalarConverter::checkIfTypeInt(void)
{
    const char *literal_c = _literal.c_str();
    char *endptr;

    long double value = strtold(literal_c, &endptr);

    if (*endptr == '\0')
    {
        _type = SCALAR_INT;
        _actual = value;
        return;
    }
}

void ScalarConverter::checkIfTypeFloat(void)
{
    // float pseudo literal check
    const std::string pseudo[4] = {"-inff", "+inff", "inff", "nanf"};
    for (int i = 0; i < 4; i++)
    {
        if (_literal == pseudo[i])
        {
            _type = SCALAR_FLOAT;
            switch (i)
            {
            case 0:
                _actual = -INFINITY;
                break;
            case 1:
                _actual = INFINITY;
                break;
            case 2:
                _actual = INFINITY;
                break;
            case 3:
                _actual = NAN;
                break;
            }
            return;
        }
    }

    // float literal check
    const char *literal_c = _literal.c_str();
    long double value = strtold(literal_c, NULL);

    // 숫자를 포함한 상태에서 문자 'f' 및 '.'가 각각 하나씩 있어야 함
    // 'f'는 무조건 끝
    // "42.f" (o)  ".42f" (o)  "42f" (x)  ".f" (x)
    // if (*(_literal.end()) != 'f')
    if (_literal == ".f")
        return;
    if (!(*std::prev(_literal.end()) == 'f' && *_literal.end() == '\0'))
        return;
    if (_literal.find_first_of('f') != _literal.find_last_of('f'))
        return;
    if (_literal.find('.') == std::string::npos || _literal.find_first_of('.') != _literal.find_last_of('.'))
        return;

    // 마지막 자리 f를 제외하고 순회하며 체크
    std::string::const_iterator it = _literal.begin();
    if (*_literal.begin() == '-')
        it++;
    while (it < _literal.end())
    {
        if (!(isdigit(*it) || *it == '.' || *it == 'f'))
            return;
        it++;
    }

    _type = SCALAR_FLOAT;
    _actual = value;
}

void ScalarConverter::checkIfTypeDouble(void)
{
    // double pseudo literal check
    const std::string pseudo[4] = {"-inf", "+inf", "inf", "nan"};
    for (int i = 0; i < 4; i++)
    {
        if (_literal == pseudo[i])
        {
            _type = SCALAR_DOUBLE;
            switch (i)
            {
            case 0:
                _actual = -INFINITY;
                break;
            case 1:
                _actual = INFINITY;
                break;
            case 2:
                _actual = INFINITY;
                break;
            case 3:
                _actual = NAN;
                break;
            }
            return;
        }
    }

    // double literal check
    const char *literal_c = _literal.c_str();
    long double value = strtold(literal_c, NULL);

    // 숫자를 포함한 상태에서 문자 '.'가 하나 있어야 함
    // "42.42" (o) "42." (o) ".42" (o) "." (x)
    if (_literal == ".")
        return;
    if (_literal.find('.') == std::string::npos || _literal.find_first_of('.') != _literal.find_last_of('.'))
        return;

    // 마지막 자리 f를 제외하고 순회하며 체크
    std::string::const_iterator it = _literal.begin();
    if (*_literal.begin() == '-')
        it++;
    while (it < _literal.end())
    {
        if (!(isdigit(*it) || *it == '.'))
            return;
        it++;
    }

    _type = SCALAR_DOUBLE;
    _actual = value;
}

void ScalarConverter::detectType(void)
{
    checkIfTypeChar();
    checkIfTypeInt();
    checkIfTypeFloat();
    checkIfTypeDouble();
    if (_type == SCALAR_NONE)
        throw(DoesNotBelongAnyTypesException());
}

void ScalarConverter::printToChar(void)
{
    std::cout << "char: ";
    if (std::numeric_limits<char>::min() <= _actual && _actual <= std::numeric_limits<char>::max())
    {
        if (std::isprint(_actual))
            std::cout << '\'' << actualToChar() << '\'' << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printToInt(void)
{
    std::cout << "int: ";
    if (std::numeric_limits<int>::min() <= _actual && _actual <= std::numeric_limits<int>::max())
        std::cout << actualToInt() << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printToFloat(void)
{
    std::cout << "float: ";
    if (std::isnan(_actual) || std::isinf(_actual))
        std::cout << actualToFloat() << 'f' << std::endl;
    else if (-std::numeric_limits<float>::max() <= _actual && _actual <= std::numeric_limits<float>::max())
    {
        if (_actual == truncl(_actual))
            std::cout << std::fixed << std::setprecision(0) << actualToFloat() << ".0f" << std::endl;
			// 출력 형식 xx.0f 꼴로 맞춰주기 위함 (구색 갖추기...)
        else
            std::cout << std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << actualToFloat() << 'f' << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printToDouble(void)
{
    std::cout << "double: ";
    if (std::isnan(_actual) || std::isinf(_actual))
        std::cout << actualToDouble() << std::endl;
    else if (-std::numeric_limits<double>::max() <= _actual && _actual <= std::numeric_limits<double>::max())
    {
        if (_actual == truncl(_actual))
            std::cout << std::fixed << std::setprecision(0) << actualToDouble() << ".0" << std::endl;
			// 출력 형식 xx.0 꼴로 맞춰주기 위함 (구색 갖추기...)
        else
            std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << actualToDouble() << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

/*
1. 들어온 리터럴에 대해 타입 판별 (char, int, float, double 순서대로)
2. actual type으로 컨버팅
*/
void ScalarConverter::convert(std::string &literal)
{
    _literal = literal;
    _type = SCALAR_NONE;
    try
    {
        detectType();
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << '\n';
        if (typeid(e) == typeid(DoesNotBelongAnyTypesException))
            return;
    }
    printToChar();
    printToInt();
    printToFloat();
    printToDouble();
}

void ScalarConverter::printDetectedResult(void)
{
    std::cout << "--------------------------------" << std::endl;
    // std::cout << std::fixed << std::setprecision(6);
	std::cout << std::scientific;
    std::cout << "type: " << _type << std::endl;
    std::cout << "actual: " << _actual << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
}

const char *ScalarConverter::DoesNotBelongAnyTypesException::what(void) const throw()
{
    return ("This literal does not belong to any scalar types");
}

const char *ScalarConverter::TooLargeValueToDisplayException::what(void) const throw()
{
    return ("The value represented by this literal is too large, impossible to display any primitive type");
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &orig)
{
    (void)orig;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &orig)
{
    (void)orig;
    return (*this);
}
