#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

std::ifstream BitcoinExchange::_file_market_price;
std::ifstream BitcoinExchange::_file_target;
std::map<std::string, float> BitcoinExchange::_market_price; // <date, price per 1 coin (exchange_rate)>

void BitcoinExchange::openMarketPriceFile(const std::string &path)
{
    _file_market_price.open(path);
    if (!_file_market_price.good())
        throw(CouldNotOpenFileException(path));
}

void BitcoinExchange::openTargetFile(const std::string &path)
{
    _file_target.open(path);
    if (!_file_target.good())
        throw(CouldNotOpenFileException(path));
}

// parse 2-field CSV file
void BitcoinExchange::parseMarketPriceFile(void)
{
    std::string line;

    std::getline(_file_market_price, line);
    while (std::getline(_file_market_price, line))
    {
        if (!isValidFormatMarketPriceLine(line))
            throw(InvalidMarketPriceFileException(line));
        size_t delim_pos = line.find(',');
        std::string date = line.substr(0, delim_pos);
        std::string price = line.substr(delim_pos + 1);

        _market_price[date] = atof(price.c_str());
    }
}

void BitcoinExchange::evaluateByLine(const std::string &line)
{
    try
    {
        if (!isValidFormatTargetLine(line))
            throw(BadInputException(line));
        size_t delim_pos = line.find('|');
        std::string date = line.substr(0, delim_pos - 1);
        float value = atof(line.substr(delim_pos + 2).c_str());
        if (value <= 0)
            throw(NotPositiveNumberException());
        else if (value >= 1000)
            throw(TooLargeNumberException());

        float result = value * getProperMarketPrice(date);
        std::cout << date << " => " << value << " = " << result << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void BitcoinExchange::evaluateAndDisplay(void)
{
    std::string line;

    try
    {
        std::getline(_file_target, line);
        if (line != "date | value")
            throw(BadInputException(line));
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << '\n';
        return;
    }

    while (std::getline(_file_target, line))
        evaluateByLine(line);
}

/*
2010-08-20,0.07
2010-08-20,,,,0.07 <- 오류로 판별
*/
// exchange_rate 제한은 딱히 없음
bool BitcoinExchange::isValidFormatMarketPriceLine(const std::string &line)
{
    size_t delim_pos = line.find(',');
    if (delim_pos == std::string::npos)
        return (false);

    std::string date = line.substr(0, delim_pos);
    std::string exchange_rate = line.substr(delim_pos + 1);

    if (!isIso8601DateStr(date) || !isValidDate(date))
        return (false);
    if (!isFloatStr(exchange_rate))
        return (false);
    return (true);
}

/*
format: date | value
date: Year-Month-Day (월: 1~12, 일: 1~30 or 31 or 28) (윤년 확인할 것)
value: float or a positive integer, between 0 and 1000 (0 < n < 1000)
ex) 2011-01-03 | 3
*/
bool BitcoinExchange::isValidFormatTargetLine(const std::string &line)
{
    size_t delim_pos = line.find('|');
    if (delim_pos == std::string::npos)
        return (false);
    if (line[delim_pos - 1] != ' ' || line[delim_pos + 1] != ' ')
        return (false);

    std::string date = line.substr(0, delim_pos - 1);
    std::string value_str = line.substr(delim_pos + 2);
    float value_f = atof(value_str.c_str());

    if (!isIso8601DateStr(date) || !isValidDate(date))
        return (false);
    if (!isFloatStr(value_str))
        return (false);
    return (true);
}

bool BitcoinExchange::isIso8601DateStr(const std::string &str)
{
    if (str.length() != 10)
        return (false);
    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    if (str[4] != '-')
        return (false);
    for (int i = 0; i < 2; i++)
    {
        if (!isdigit(str[5 + i]))
            return (false);
    }
    if (str[7] != '-')
        return (false);
    for (int i = 0; i < 2; i++)
    {
        if (!isdigit(str[8 + i]))
            return (false);
    }
    return (true);
}

bool BitcoinExchange::isFloatStr(const std::string &str)
{
    bool point_exist = false;
    bool digit_exist = false;
    int i = 0;

    if (str[0] == '-')
        i++;
    else if (!isdigit(str[0]) )
        return (false);

    while (str[i])
    {
        if (str[i] == '.')
        {
            if (point_exist == false)
                point_exist = true;
            else
                return (false);
        }
        else if (!isdigit(str[i]))
            return (false);
        digit_exist = true;
        i++;
    }
    return (digit_exist);
}

// date: Year-Month-Day (월: 1~12, 일: 1~30 or 31 or 28) (윤년 확인할 것)
// 1-31, 2-28, 3-31, 4-30, 5-31, 6-30, 7-31, 8-31, 9-30, 10-31, 11-30, 12-31
// 값 검증
bool BitcoinExchange::isValidDate(const std::string &date)
{
    // check leap year
    size_t delim_pos1 = date.find('-');
    size_t delim_pos2 = date.find('-', delim_pos1 + 1);

    int year = atoi(date.substr(0, delim_pos1).c_str());
    int month = atoi(date.substr(delim_pos1 + 1, 2).c_str());
    int day = atoi(date.substr(delim_pos2 + 1, 2).c_str());

    // check month
    if (!(1 <= month && month <= 12))
        return (false);

    // check day
    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (1 <= day && day <= 29);
        else
            return (1 <= day && day <= 28);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return (1 <= day && day <= 30);
    else
        return (1 <= day && day <= 31);
    return (true);
}

float BitcoinExchange::getProperMarketPrice(const std::string &date)
{
    // TODO: 구현
    return (0);
}
