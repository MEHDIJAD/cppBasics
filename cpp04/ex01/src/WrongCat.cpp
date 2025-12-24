#include "../incl/WrongCat.hpp"

/* Default Costructor */
WrongCat::WrongCat( void ) : WrongAnimal() {

	this->type = "WrongCat";
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
}

/* Copy Costructor */
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	std::cout << GREEN << this->getType() << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

/* Assigment Operator */
WrongCat &WrongCat::operator=(const WrongCat &other){
	if(this != &other){
		WrongAnimal::operator=(other);
	}
	return (*this);
}

/* Destructor */
WrongCat::~WrongCat ( void ){
	std::cout <<  GREEN <<  "WrongCat " << RESET << "Destructor called" << std::endl;	
}

void WrongCat::makeSound( void ) const {
	std::cout << GREEN << "WrongCat Say MEOW MEOW🐱🐱" << std::endl;
}
