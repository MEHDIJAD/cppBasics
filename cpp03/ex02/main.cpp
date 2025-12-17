#include "incl/FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "|- FragTrap TEST -|" << std::endl;
	FragTrap f("FR4G-TP");
	f.attack("arget-2");
	f.takeDamage(8);
	f.beRepaired(11);
	f.highFivesGuys();
	
	return (0);
}
