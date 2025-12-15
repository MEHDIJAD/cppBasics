#include "../incl/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << YELLOW << "ScavTrap" << RESET << " Default Constructor called" << std::endl;
}

/*! @brief The initializer list is for:
	- Calling the base class constructor.
	- Initializing the derived class's own members.
	*/
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) /* We CAN'T call then here */{
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 20;
	std::cout << YELLOW << "ScavTrap" << RESET << " " << this->getName() << " Constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void ){
	std::cout << YELLOW << "ScavTrap" << RESET << " " << this->getName() << " Destructor called" << std::endl;
}


/**
 * @brief Makes the ScavTrap attack a target.
 * @param target The name of the target to attack.
 * 	IF: ScavTrap can’t do anything if it has no hit points or
	energy points left
	OUTPUT: ScavTrap <name> attacks <target>, causing <damage> points of damage!
 */
void ScavTrap::attack(const std::string &target)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << RED << "ScavTrap" << RESET << " " << this->getName()
		<< RED << " can't attack, not enough hit points or energy points left!"
		<< RESET << std::endl;
		return;
	}
	this->_EnergyPoint--; /* Attacking cost 1 energy point*/
	std::cout << YELLOW << "ScavTrap" << RESET << " " << this->getName()
	<< " attacks " << target
	<< ", causing " <<  this->_AttackDamage << " points of damage!"
	<< std::endl;
}
/**
 * @brief Makes the ScavTrap take damage.
 * @param amount The amount of damage to take.
 */
void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoint == 0)
	{
		std::cout << RED << "ScavTrap" << RESET << " "
		<< this->getName() << RED << " is already knocked out!" << RESET << std::endl;
		return;
	}
	if (this->_HitPoint < amount)
		this->_HitPoint = 0;
	else
		this->_HitPoint -= amount;
	std::cout << RED << "ScavTrap" << RESET << " "
	<< this->getName() << " takes "
	<< amount << " points of damage! Current HP: "
	<< this->_HitPoint << std::endl;
}
/**
 * @brief Makes the ScavTrap repair itself.
 * @param amount The amount of hit points to restore.
 */
void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << RED << "ScavTrap" << RESET << " "
		<< this->getName() << RED << " can't be repaired, not enough hit points or energy points left!" << RESET << std::endl;
		return;
	}
	this->_EnergyPoint--;
	this->_HitPoint += amount;
	std::cout << GREEN << "ScavTrap" << RESET << " "
	<< this->getName() << " repairs itself for "
	<< amount << " points! Current HP: "
	<< this->_HitPoint << std::endl;
}
void ScavTrap::guardGate( void )
{
	std::cout << YELLOW << "ScavTrap" << RESET << " is now in Gate Keeper mode." << std::endl;
}
