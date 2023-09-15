#include "PhoneBook.hpp"
#include "utils.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string input;
    bool result;

    phonebook.showWelcome();
    while (1)
    {
        phonebook.showHowToUse();
        try
        {
            utils::getStringNotOnlySpaces(input, "$ ");
            result = false;
            if (input == "ADD")
                result = phonebook.add();
            else if (input == "SEARCH")
                result = phonebook.search();
            else if (input == "EXIT")
                break;
            else
                std::cout << "\nError: Invalid command" << std::endl;

            if (result == true)
                std::cout << "\nSuccessfully done." << std::endl;
        }
        catch (int exception)
        {
            std::cout << '\n' << "EOF has been entered and standard input is no longer possible." << std::endl;
            break;
        }
    }
    std::cout << "Exit program" << std::endl;
}
