#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) {
	std::cout << BLUE << "ClapTrap " << this->getName() << " Default Constructor called" << RESET << std::endl;
}

/**
 * @brief Constructs a new ClapTrap object with a given name and default stats.
 * @param Name The name of the ClapTrap.
 */
ClapTrap::ClapTrap(std::string Name) :
_Name(Name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << BLUE << "ClapTrap " << this->getName() << " Constructor called" << RESET << std::endl;
}

/**
 * @brief Destroys the ClapTrap object.
 */
ClapTrap::~ClapTrap( void )
{
	std::cout << BLUE << "ClapTrap " << this->getName() << " Destructor called" << RESET << std::endl;
}

/**
 * @brief Copy constructor for ClapTrap.
 * @param other The ClapTrap object to copy from.
 */
ClapTrap::ClapTrap(const ClapTrap &other) :
_Name(other._Name), _HitPoint(other._HitPoint), _EnergyPoint(other._EnergyPoint), _AttackDamage(other._AttackDamage)
{
	std::cout << BLUE << "ClapTrap " << this->getName() << " Copy constructor called" << RESET << std::endl;
}

/**
 * @brief Assignment operator for ClapTrap.
 * @param other The ClapTrap object to assign from.
 * @return A reference to the assigned ClapTrap object.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_Name = other.getName();
		this->_HitPoint = other._HitPoint;
		this->_EnergyPoint = other._EnergyPoint;
		this->_AttackDamage = other._AttackDamage;
	}
	std::cout << BLUE << "ClapTrap " << this->getName() << " Assignment operator called" << RESET << std::endl;
	return(*this);
}

/**
 * @brief Sets the name of the ClapTrap.
 * @param Name The new name for the ClapTrap.
 */
void ClapTrap::setName(std::string const Name){
	this->_Name = Name;
}

/**
 * @brief Gets the name of the ClapTrap.
 * @return The name of the ClapTrap.
 */
std::string ClapTrap::getName( void ) const {
	return (this->_Name);
}

/**
 * @brief Gets the current hit points of the ClapTrap.
 * @return The current hit points.
 */
unsigned int ClapTrap::getHitPoints( void ) const {
	return (this->_HitPoint);
}

/**
 * @brief Makes the ClapTrap attack a target.
 * @param target The name of the target to attack.
 * 	IF: ClapTrap can’t do anything if it has no hit points or
	energy points left
	OUTPUT: ClapTrap <name> attacks <target>, causing <damage> points of damage!
 */
void ClapTrap::attack(const std::string &target)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << RED << "ClapTrap " << this->getName()
		<< " can't attack, not enough hit points or energy points left!" 
		<< RESET << std::endl;
		return;
	}
	this->_EnergyPoint--; /* Attacking cost 1 energy point*/
	std::cout << YELLOW << "ClapTrap " << this->getName()
	<< " attacks " << target
	<< ", causing " <<  this->_AttackDamage << " points of damage!"
	<< RESET << std::endl;
}

/**
 * @brief Makes the ClapTrap take damage.
 * @param amount The amount of damage to take.
 */
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoint == 0)
	{
		std::cout << RED << "ClapTrap " 
		<< this->getName() << " is already knocked out!" << RESET << std::endl;
		return;
	}
	if (this->_HitPoint < amount)
		this->_HitPoint = 0;
	else
		this->_HitPoint -= amount;
	std::cout << RED << "ClapTrap "
	<< this->getName() << " takes " 
	<< amount << " points of damage! Current HP: " 
	<< this->_HitPoint << RESET << std::endl;
}

/**
 * @brief Makes the ClapTrap repair itself.
 * @param amount The amount of hit points to restore.
 */
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << RED << "ClapTrap " 
		<< this->getName() << " can't be repaired, not enough hit points or energy points left!" << RESET << std::endl;
		return;
	}
	this->_EnergyPoint--;
	this->_HitPoint += amount;
	std::cout << GREEN << "ClapTrap "
	<< this->getName() << " repairs itself for "
	<< amount << " points! Current HP: "
	<< this->_HitPoint << RESET << std::endl;
}
