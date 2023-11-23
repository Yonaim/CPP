#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

// TODO: 전체적으로 public static 함수로 선언해 사용할 것인지, 객체를 만들어 함수를 호출할 것인지 결정하기
class BitcoinExchange
{
  private:
    static std::ifstream _file_market_price;
    static std::ifstream _file_target;
    static std::map<std::string, float> _market_price; // <date, price per 1 coin (exchange_rate)>

    // for OCF (not use)
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &orig);
    BitcoinExchange &operator=(const BitcoinExchange &orig);

    // format check
    static bool isValidFormatMarketPriceLine(const std::string &line);
    static bool isValidFormatTargetLine(const std::string &line);

    // format check utils
    static bool isValidDateStr(const std::string &str);
    static bool isFloatStr(const std::string &str);
    static bool isValidDate(const std::string &date);
    static bool isValidValue(const std::string &value);
	
	// evaluate utils
    static void evaluateByLine(const std::string &line);
    static float getProperMarketPrice(const std::string &date);

  public:
    ~BitcoinExchange(){};

    // open
    static void openMarketPriceFile(const std::string &path = "./data.csv");
    static void openTargetFile(const std::string &path);

    // parse
    static void parseMarketPriceFile(void);

    // evaluate & display
    static void evaluateAndDisplay(void);

    // exception
    class CouldNotOpenFileException;
    class InvalidMarketPriceFileException;
    class BadInputException;
};

class BitcoinExchange::CouldNotOpenFileException : public std::exception
{
  private:
    std::string errormsg;

  public:
    CouldNotOpenFileException(const std::string &filename)
    {
        errormsg = "Open file '" + filename + "' failed";
    }
    virtual ~CouldNotOpenFileException() throw(){};
    const char *what(void) const throw()
    {
        return (errormsg.c_str());
    }
};
class BitcoinExchange::InvalidMarketPriceFileException : public std::exception
{
    const char *what(void) const throw()
    {
        return ("Invalid Market price file");
    }
};

class BitcoinExchange::BadInputException : public std::exception
{
  private:
    std::string errormsg;

  public:
    BadInputException(const std::string &input)
    {
        errormsg = "bad input => " + input;
    }
    virtual ~BadInputException() throw(){};
    const char *what(void) const throw()
    {
        return errormsg.c_str();
    }
};

#endif
