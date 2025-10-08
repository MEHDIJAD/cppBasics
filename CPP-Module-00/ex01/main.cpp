#include "header.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    std::string input;
    PhoneBook p;

    while (true)
    {
        std::cout << "Usage: <ADD>, <SEARCH> OR <EXIT>: "; 
         std::getline(std::cin >> std::ws, input);
        if (input == "ADD"){
            p.AddContact();
        }
        else if (input == "SEARCH"){
            p.DisplayContacts();
        }
        else if (input == "EXIT"){
            break ;
        }
    }
    return (0);
}