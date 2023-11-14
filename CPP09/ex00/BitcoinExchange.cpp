#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// TODO: 첫 라인 처리, 이후 라인 처리 중 에러 처리
// TODO: 함수 분리
void BitcoinExchange::parseCSVfile(const std::string &csv)
{
	std::ifstream infile(csv);
	if (!infile.good())
		throw (invalidCSVfileException());

	std::cout << "test" << std::endl;

	std::string line;
	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw (invalidCSVfileException());

	// 2010-08-17,0
	// 2010-08-20,0.07
	// 2010-08-20,,,,0.07 <- 오류로 판별
	while (std::getline(infile, line))
	{
		size_t delim_pos = line.find(',');
		std::string date = line.substr(0, delim_pos);
		std::string price = line.substr(delim_pos + 1);

		

		std::cout << "date: " << date << std::endl;
		std::cout << "price: " << price << std::endl;
	}
}

void BitcoinExchange::evaluateValues(std::string &input)
{

}

void BitcoinExchange::displayEvaluatedValues(void)
{

}

const char *BitcoinExchange::invalidCSVfileException::what() const throw()
{
	return ("invalid CSV file Exception");
};

const char *BitcoinExchange::invalidInputFileException::what() const throw()
{
	return ("invalid input file Exception");
};