#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap clap("MARK-1");
	clap.attack("Target-1");
	clap.takeDamage(8);
	clap.beRepaired(11);

	return (0);
}
