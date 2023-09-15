#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>

namespace utils
{
	void printFormattedLine(const std::string *strs, int strCnt);
	void getStringNotOnlySpaces(std::string &str, const std::string &prompt);
	void getStringNotOnlySpaces(std::string &str, const std::string &prompt, const std::string &retryMsg);
}

#endif