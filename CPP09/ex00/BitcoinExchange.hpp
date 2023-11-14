#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

// TODO: 전체적으로 public static 함수로 선언해 사용할 것인지, 객체를 만들어 함수를 호출할 것인지 결정하기 
class BitcoinExchange
{
	private:
	static std::map<std::string, int> history; // <date, price per 1 coin>
	static std::map<std::string, int> evaluated; // <date, evaluated value>

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &orig);
	BitcoinExchange &operator=(BitcoinExchange &orig);
	
	public:
	// BitcoinExchange(const std::string &csv= "./data.csv");
	~BitcoinExchange();

	static void parseCSVfile(const std::string &csv = "./data.csv");
	
	static void evaluateValues(std::string &input);
	static void displayEvaluatedValues(void);

	class invalidCSVfileException : public std::exception
	{
		const char* what(void) const throw();
	};

	class invalidInputFileException : public std::exception
	{
		const char* what(void) const throw();
	};
};

#endif
