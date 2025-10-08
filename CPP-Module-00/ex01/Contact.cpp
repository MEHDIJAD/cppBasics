#include "header.h"

void Contact::SetFirstName(std::string FirstName)
{
    try
    {
        size_t i = -1;
        while (++i < FirstName.length()) {
        if (!isalpha(FirstName[i])){
            throw std::invalid_argument("First name must contain only letters.");
            // ❗ Stop execution here and jump to catch if input is invalid
            }
        }
            _FirstName = FirstName;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid first name: " << e.what() << std::endl;
    }   
}

std::string Contact::FirstName() {
    return (_FirstName);
}

void Contact::SetLastName(std::string LastName)
{
    try
    {
        size_t i = -1;
        while (++i < LastName.length()) {
            if (!isalpha(LastName[i])){
                throw std::invalid_argument("First name must contain only letters.");
                // ❗ Stop execution here and jump to catch if input is invalid
            }
        }
        _LastName = LastName;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid first name: " << e.what() << std::endl;
    }   
}

std::string Contact::LastName(){
    return (_LastName);
}

void Contact::SetNickname(std::string Nickname){
    _Nickname = Nickname;
}

std::string Contact::Nickname(){
    return (_Nickname);
}

void Contact::SetPhoneNumber(int PhoneNumber) {
    _PhoneNumber = PhoneNumber;
}

int Contact::PhoneNumber(){
    return (_PhoneNumber);
}

void Contact::SetDarkestSecret(std::string DarkestSecret) {
     _DarkestSecret = DarkestSecret;
}

std::string Contact::DarkestSecret() {
    return (_DarkestSecret);
}
