#include "utils.hpp"

namespace utils
{
void printFormattedLine(const std::string *strs, int strCnt)
{
    for (int i = 0; i < strCnt; i++)
    {
        std::cout << std::setw(10);
        // std::right is default
        if (strs[i].size() >= 10)
            std::cout << strs[i].substr(0, 9) + ".";
        else
            std::cout << strs[i];
        std::cout << '|';
    }
    std::cout << std::endl;
}

void getStringNotOnlySpaces(std::string &str, const std::string &prompt, const std::string &retryMsg)
{
    while (1)
    {
        std::cout << prompt;
        getline(std::cin, str);
        if (std::cin.eof() == true)
            throw(0);
        if (str.find_first_not_of(" \t\r\v\f") != std::string::npos)
            break;
        std::cout << retryMsg << std::endl;
    }
}

void getStringNotOnlySpaces(std::string &str, const std::string &prompt)
{
    while (1)
    {
        std::cout << prompt;
        getline(std::cin, str);
        if (std::cin.eof() == true)
            throw(0);
        if (str.find_first_not_of(" \t\r\v\f") != std::string::npos)
            break;
    }
}
}