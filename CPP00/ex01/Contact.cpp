#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number,
                 std::string darkest_secret)
{
    this->_first_name = first_name;
    this->_last_name = last_name;
    this->_nickname = nickname;
    this->_phone_number = phone_number;
    this->_darkest_secret = darkest_secret;
}

void Contact::displaySummary(int idx) const
{
    std::string strs[] = {std::to_string(idx), this->_first_name, this->_last_name, this->_nickname};

    utils::printFormattedLine(strs, 4);
}

void Contact::displayAll(int idx) const
{
    const std::string columnTitles[6] = {"Index",    "First name",   "Last name",
                                         "Nickname", "Phone number", "Darkest secret"};

    std::cout << "- " << columnTitles[0] << ": " << std::to_string(idx) << "\n";
    std::cout << "- " << columnTitles[1] << ": " << this->_first_name << "\n";
    std::cout << "- " << columnTitles[2] << ": " << this->_last_name << "\n";
    std::cout << "- " << columnTitles[3] << ": " << this->_nickname << "\n";
    std::cout << "- " << columnTitles[4] << ": " << this->_phone_number << "\n";
    std::cout << "- " << columnTitles[5] << ": " << this->_darkest_secret;
    std::cout << std::endl;
}