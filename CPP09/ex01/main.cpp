#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: ./RPN <expression>" << std::endl;
        return (1);
    }
    (void)argv;
	RPN rpn("8 9   * 9 - 9 - 9 - 4 - 1 +");
    std::cout << rpn.result() << std::endl;

}
