#include "Zombie.hpp"

/* Constructor */
Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Costruct a Zombie: " << this->name << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Destructor */
Zombie::~Zombie(void)
{
    std::cout  << "Destruct a Zombie: " << this->name << std::endl;
}
