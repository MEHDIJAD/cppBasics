#include "header.h"

PhoneBook::PhoneBook() : _numContacts(0), _nextIndex(0){

}

void PhoneBook::AddContact(/*Contact &contacts*/)
{
    Contact newContact;
    std::string Input;
    int          Phone;

    std::cout << "Enter First name: ";
    std::getline(std::cin >> std::ws, Input);
    newContact.SetFirstName(Input);

    std::cout << "Enter Last name: ";
    std::getline(std::cin, Input);
    newContact.SetLastName(Input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, Input);
    newContact.SetNickname(Input);

    while (true)
    {
        std::cout << "Enter Phone Number: ";
        std::cin >> Phone;

        if (std::cin.fail()){
            std::cout << "Invalid input. Please enter a number for the phone number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            newContact.SetPhoneNumber(Phone);
            break;
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "What is your Darkest Secret: ";
    std::getline(std::cin, Input);
    newContact.SetDarkestSecret(Input); 
    
    _contacts[_nextIndex] = newContact;

    if (_numContacts < 8){
        _numContacts++;
    }

    _nextIndex = (_nextIndex + 1) % 8; 
}

std::string truncate_string(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

void PhoneBook::DisplayContacts()
{
    if (_numContacts == 0){
        std::cout << "PhoneBook is empty. No contacts to display." << std::endl;
        return ;
    }

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    int i = 0;
    
    while (i < _numContacts)
    {
        std::cout << "|" << std::right << std::setw(10) << i;
        std::cout << "|" << std::right << std::setw(10) << truncate_string(_contacts[i].FirstName(), 10);
        std::cout << "|" << std::right << std::setw(10) << truncate_string(_contacts[i].LastName(), 10);
        std::cout << "|" << std::right << std::setw(10) << truncate_string(_contacts[i].Nickname(), 10);
        std::cout << "|" << std::endl;

        i++;
    }
    std::cout << "--------------------------------------------" << std::endl;

}

// void OneContact(unsigned int index)
// {

// }
