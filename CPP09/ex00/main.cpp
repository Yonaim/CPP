#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: ./btc <input_file>" << std::endl;
        return (1);
    }

    try
    {
        BitcoinExchange bitcoin_exchange;
        bitcoin_exchange.openMarketPriceFile();
        bitcoin_exchange.openTargetFile(argv[1]);
        bitcoin_exchange.parseMarketPriceFile();
        bitcoin_exchange.evaluateAndDisplay();
    }
    catch (std::exception &e)
    {
        std::cout << "\033[0;31m"
                  << "Error: " << e.what() << "\033[0m" << std::endl;
        return (1);
    }
    return (0);
}
