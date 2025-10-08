#include "header.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    std::string input;
    PhoneBook p;

    while (true)
    {
        std::cout << "Usage: <ADD>, <SEARCH> OR <EXIT>: "; 
        std::cin >> input;
        if (input == "ADD"){
            p.AddContact();
        }
        else if (input == "SEARCH"){
            // Display all contact 
        }
        else if (input == "EXIT"){
            break ;
        }
    }
    return (0);
}