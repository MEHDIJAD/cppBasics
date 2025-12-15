#include "incl/ScavTrap.hpp"
#include "incl/FragTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap p("MAEK-1");
	p.attack("Target-1");
	p.guardGate();
	
	std::cout << std::endl;
	
	FragTrap f("FR4G-TP");
	f.attack("arget-2");
	f.highFivesGuys();

	std::cout << std::endl;
	return (0);
}
