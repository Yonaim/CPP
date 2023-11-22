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
        std::string target(argv[1]);
        BitcoinExchange::openMarketPriceFile();
        BitcoinExchange::openTargetFile(target);
        BitcoinExchange::parseMarketPrice();
        BitcoinExchange::evaluateTarget();
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        return (1);
    }

    // BitcoinExchange::displayEvaluated();
    return (0);
}
