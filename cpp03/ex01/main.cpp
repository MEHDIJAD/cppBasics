#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "|- ScavTrap TEST -|" << std::endl;
	ScavTrap p("MAEK-2");
	p.attack("Cat-1");
	p.takeDamage(8);
	p.beRepaired(11);
	p.guardGate();
	
	return (0);
}
