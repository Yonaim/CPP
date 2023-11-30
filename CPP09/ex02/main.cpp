#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "Usage: PmergeMe <positive_integer_sequence>" << std::endl;
        return (1);
    }

    try
    {
		PmergeMe pmergeme((const char **)argv + 1);
        pmergeme.sortAndDisplay();
    }
    catch (std::exception &e)
    {
        std::cout << "\033[0;31m"
                  << "Error: " << e.what() << "\033[0m" << std::endl;
        return (1);
    }
    return (0);	
}
