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
    bool isValidFormatMarketPriceLine(const std::string &line) const;
    bool isValidFormatTargetLine(const std::string &line) const;
    bool isIso8601DateStr(const std::string &str) const;
    bool isValidDate(const std::string &date) const;
    bool isNumeric(const std::string &str) const;

    // evaluate utils
    void evaluateByLine(const std::string &line) const;
    float getMarketPrice(const std::string &date) const;

  public:
    BitcoinExchange(const std::string &target_path, const std::string &csv_path = "data.csv");
    ~BitcoinExchange();

    void openMarketPriceFile(const std::string &path);
    void openTargetFile(const std::string &path);
    void parseMarketPriceFile(void);
    void evaluate(void);

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
    virtual ~CouldNotOpenFileException() throw();
    const char *what(void) const throw();
};

class BitcoinExchange::InvalidMarketPriceFileException : public std::exception
{
  private:
    std::string errormsg;

  public:
    InvalidMarketPriceFileException(int nth);
    virtual ~InvalidMarketPriceFileException() throw();
    const char *what(void) const throw();
};

class BitcoinExchange::BadInputException : public std::exception
{
  private:
    std::string errormsg;

  public:
    BadInputException(const std::string &input);
    virtual ~BadInputException() throw();
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
