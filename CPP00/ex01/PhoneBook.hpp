#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
    Contact _contacts[8];
    int _front;
    int _count;

  public:
    PhoneBook();
    void showWelcome() const;
    void showHowToUse() const;
    bool add();
    bool search() const;
};

#endif