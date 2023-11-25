#include "RPN.hpp"
#include <iostream>

/*
8 9   * 9 - 9 - 9 - 4 - 1 +

(4 + 5) / (2 - 1)

4 5 + 2 1 - /

*/
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: ./RPN <expression>" << std::endl;
        return (1);
    }

    try
    {
        std::string exp(argv[1]);
        RPN rpn(exp);
        // std::cout << "\033[0;3가2m" << "\n>>> RESULT: " << rpn.result() << '\n' << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[0;31m"
                  << "Error: " << e.what() << "\033[0m" << std::endl;
        return (1);
    }
}
