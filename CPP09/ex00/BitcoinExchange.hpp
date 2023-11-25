#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{
  private:
    std::ifstream _file_market_price;
    std::ifstream _file_target;
    std::map<std::string, float> _market_price; // <date, price per 1 coin (exchange_rate)>

    // for OCF (not use)
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &orig);
    BitcoinExchange &operator=(const BitcoinExchange &orig);

    // format check
    bool isValidFormatMarketPriceLine(const std::string &line);
    bool isValidFormatTargetLine(const std::string &line);
    bool isIso8601DateStr(const std::string &str);
    bool isValidDate(const std::string &date);
    bool isFloatStr(const std::string &str);

    // evaluate utils
    void evaluateByLine(const std::string &line);
    float getMarketPrice(const std::string &date);

  public:
    BitcoinExchange(const std::string &target_path, const std::string &csv_path = "data.csv");
    ~BitcoinExchange();

    // open
    void openMarketPriceFile(const std::string &path = "./data.csv");
    void openTargetFile(const std::string &path);

    // parse
    void parseMarketPriceFile(void);

    // evaluate & display
    void evaluateAndDisplay(void);

    // exception
    class CouldNotOpenFileException;
    class InvalidMarketPriceFileException;
    class BadInputException;
    class NotPositiveNumberException;
    class TooLargeNumberException;
    class TooLowerDateException;
};

class BitcoinExchange::CouldNotOpenFileException : public std::exception
{
  private:
    std::string errormsg;
  public:
    CouldNotOpenFileException(const std::string &filename);
    virtual ~CouldNotOpenFileException() throw(){};
    const char *what(void) const throw();
};

class BitcoinExchange::InvalidMarketPriceFileException : public std::exception
{
  private:
    std::string errormsg;
  public:
    InvalidMarketPriceFileException(int nth);
    virtual ~InvalidMarketPriceFileException() throw(){};
    const char *what(void) const throw();
};

class BitcoinExchange::BadInputException : public std::exception
{
  private:
    std::string errormsg;
  public:
    BadInputException(const std::string &input);
    virtual ~BadInputException() throw(){};
    const char *what(void) const throw();
};

class BitcoinExchange::NotPositiveNumberException : public std::exception
{
    const char *what(void) const throw();
};

class BitcoinExchange::TooLargeNumberException : public std::exception
{
    const char *what(void) const throw();
};

class BitcoinExchange::TooLowerDateException : public std::exception
{
    const char *what(void) const throw();
};

#endif
