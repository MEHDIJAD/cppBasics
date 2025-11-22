#include "Harl.hpp"
#include <iostream>

void harl::debug( void ){
    std::cout << BLUE
    << "[DEBUG] Just checking... Is this thing on? Love me some bacon."
    << RESET << std::endl;
}

void harl::info( void ){
    std::cout << GREEN
    << "[INFO] FYI: More bacon isn't free. And I wanted more bacon."
    << RESET << std::endl;
}
void harl::warning( void )
{
    std::cout << YELLOW
    << "[WARNING] Bacon levels are dangerously low. I've been a customer forever!"
    << RESET << std::endl;
}

void harl::error( void ){
    std::cout << RED
    << "[ERROR] THIS IS A DISASTER! WHERE IS THE MANAGER AND THE BACON?!"
    << RESET << std::endl;
}



void harl::complain(std::string level)
{
    t_complain complain[] = {
        {"DEBUG", &harl::debug},
        {"INFO", &harl::info},
        {"WARNING", &harl::warning},
        {"ERROR", &harl::error}
    };

    for(int i = 0; i < 4; ++i)
    {
        if(complain[i].level == level){
            (this->*(complain[i].action))();
            return ;
        }
    }
}

