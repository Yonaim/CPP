#include "BitcoinExchange.hpp"

#include <iostream>

// TODO: 윤년
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "usage: ./btc <input_file>" << std::endl;
		return (1);
	}

	try
	{
		std::string input(argv[1]);
		BitcoinExchange::parseCSVfile();
		BitcoinExchange::evaluateValues(input);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	BitcoinExchange::displayEvaluatedValues();
	return (0);
}
