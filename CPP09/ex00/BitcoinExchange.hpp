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
    static std::map<std::string, int> _market_price; // <date, price per 1 coin (exchange_rate)>
    // static std::map<std::string, int> _evaluated;    // <date, evaluated value>

    // for OCF (not use)
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &orig);
    BitcoinExchange &operator=(const BitcoinExchange &orig);

    // format check
    static bool isValidMarketPriceLineFormat(const std::string &line);
    static bool isValidTargetLineFormat(const std::string &line);
    static bool isValidDateStr(const std::string &date);
    static bool isFloatStr(const std::string &date);
    // 
    static bool isValidDate(const std::string &date);
    static bool isValidValue(const std::string &value);

  public:
    ~BitcoinExchange();

    static void openMarketPriceFile(const std::string &path = "./data.csv");
    static void openTargetFile(const std::string &path);
    static void parseMarketPrice(void);
    static void evaluateTarget(void);
    // static void displayEvaluated(void);

    class OpenFileFailedException : public std::exception
    {
      private:
        std::string _filename;

      public:
        OpenFileFailedException(const std::string &filename) : _filename(filename)
        {
        }
        virtual ~OpenFileFailedException() throw();
        const char *what(void) const throw()
        {
            return (("Open file '" + _filename + "' failed").c_str());
        }
    };

    class InvalidFileFormatException : public std::exception
    {
      private:
        std::string _filename;
        int _nth_line;

      public:
        InvalidFileFormatException(const std::string &filename, int nth_line) : _filename(filename), _nth_line(nth_line)
        {
        }
        virtual ~InvalidFileFormatException() throw();
        const char *what(void) const throw()
        {
            std::stringstream ss;
            ss << _nth_line;
            std::string nth_line_str = ss.str();
            return (("Invalid file format '" + _filename + "' : line " + nth_line_str).c_str());
        }
    };

    class TooLargeNumberException : public std::exception
    {
      const char* what(void) const throw();
    };

};

#endif
