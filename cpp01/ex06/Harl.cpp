#include "Harl.hpp"
#include <iostream>

void harl::debug( void ){
    std::cout << BLUE << "[ DEBUG ]" << std::endl;
    std::cout << "Just checking... Is this thing on? Love me some bacon." << RESET << std::endl;
}

void harl::info( void ){
    std::cout << GREEN << "[ INFO ]" << std::endl;
    std::cout << "FYI: More bacon isn't free. And I wanted more bacon." << RESET << std::endl;
}
void harl::warning( void )
{
    std::cout << YELLOW << "[ WARNING ]" << std::endl;
    std::cout << "Bacon levels are dangerously low. I've been a customer forever!" << RESET << std::endl;
}

void harl::error( void ){
    std::cout << RED << "[ ERROR ]" << std::endl;
    std::cout << "THIS IS A DISASTER! WHERE IS THE MANAGER AND THE BACON?!" << RESET << std::endl;
}


static Level getLevelFromString(std::string level){
    std::string levels[] = {"DEBUG", "INFO", "WARNING","ERROR"};
    for (int i = 0; i < 4; i++){
        if (levels[i] == level){
            return static_cast<Level>(i); //? what is this
        }
    }
    return (NONE);
}

void harl::complain( std::string level )
{
    /* map string to enume */
    Level filterLevel = getLevelFromString(level);

    switch (filterLevel)
    {
    case DEBUG:
        this->debug();
        // fallthrough
    case INFO:
        this->info();
        // fallthrough
    case WARNING:
        this->warning();
        // fallthrough
    case ERROR:
        this->error();
        break;
    case NONE:
        std::cout << GRAY << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
        break;
    default:
        break;
    }
}