#include "../incl/WrongCat.hpp"

/**
 * @brief Default constructor for WrongCat.
 */
WrongCat::WrongCat( void ) : WrongAnimal() {

	this->type = "WrongCat";
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
}

/**
 * @brief Copy constructor for WrongCat.
 * @param other The other WrongCat object to copy.
 */
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	std::cout << GREEN << this->getType() << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for WrongCat.
 * @param other The other WrongCat object to assign from.
 * @return A reference to the current WrongCat object.
 */
WrongCat &WrongCat::operator=(const WrongCat &other){
	if(this != &other){
		WrongAnimal::operator=(other);
	}
	return (*this);
}

/**
 * @brief Destructor for WrongCat.
 */
WrongCat::~WrongCat ( void ){
	std::cout <<  GREEN <<  "WrongCat " << RESET << "Destructor called" << std::endl;	
}

/**
 * @brief Makes the wrong cat sound.
 */
void WrongCat::makeSound( void ) const {
	std::cout << GREEN << "WrongCat Say MEOW MEOW🐱🐱" << std::endl;
}
