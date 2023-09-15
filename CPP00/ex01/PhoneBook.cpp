#include <sstream>

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook()
{
    this->_front = 0;
    this->_count = 0;
}

void PhoneBook::showWelcome() const
{
    std::cout << "\n==========================================================\n\n";
    std::cout << "                   ~ My Awesome PhoneBook ~";
    std::cout << "\n\n==========================================================";
    std::cout << std::endl;
}

void PhoneBook::showHowToUse() const
{
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    std::cout << "Please enter one of the commands below.\n";
    std::cout << "\t'ADD': Add the contact\n";
    std::cout << "\t'SEARCH': Search the contact\n";
    std::cout << "\t'EXIT': exit this program and delete all data\n";
}

bool PhoneBook::add()
{
    const std::string columnTitles[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
    std::string input[5];
    std::size_t found;
    for (int i = 0; i < 5; i++)
    {
        utils::getStringNotOnlySpaces(input[i], ">> " + columnTitles[i] + ": ", "Field of contact cannot be empty");
        found = input[i].find_first_not_of(" \t\f\v\r");
        input[i].erase(0, found);
    }

    Contact new_contact(input[0], input[1], input[2], input[3], input[4]);
    if (_count == 8)
    {
        this->_contacts[_front] = new_contact;
        this->_front = (this->_front + 1) % 8;
    }
    else
    {
        this->_contacts[_count] = new_contact;
        this->_count++;
    }
    return (true);
}

bool PhoneBook::search() const
{
    if (this->_count == 0)
    {
        std::cout << '\n' << "Your PhoneBook is empty." << std::endl;
        return (false);
    }

    const std::string columnTitles[6] = {"Index",    "First name",   "Last name",
                                         "Nickname", "Phone number", "Darkest secret"};
    std::cout << '\n';
    utils::printFormattedLine(columnTitles, 4);
    for (int i = 0; i < this->_count; i++)
        this->_contacts[i].displaySummary(i);

    int idx;
    {
        std::string input;
        std::stringstream ss;
        std::cout << '\n';
        utils::getStringNotOnlySpaces(input, "Please enter the index you want: ");
        ss.str(input);
        ss >> idx;
        if (std::cin.eof() == true)
            throw(0);
        if (ss.fail() == true || ss.eof() == false || !(0 <= idx && idx < this->_count))
        {
            std::cout << '\n' << "Error: Out of range or wrong index" << std::endl;
            std::cin.clear();
            return (false);
        }
    }
    std::cout << '\n';
    this->_contacts[idx].displayAll(idx);
    return (true);
}
