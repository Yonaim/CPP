#include "RPN.hpp"
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: RPN <expression>" << std::endl;
        return (1);
    }

    try
    {
        std::string exp(argv[1]);
        RPN rpn(exp);
        int result = rpn.result();
        std::cout << "\033[0;32m" << "\n>>> RESULT: " << result << '\n' << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[0;31m"
                  << "Error: " << e.what() << "\033[0m" << std::endl;
        return (1);
    }
}
