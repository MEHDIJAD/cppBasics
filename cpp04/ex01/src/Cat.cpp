#include "../incl/Cat.hpp"

/* Default Costructor */
Cat::Cat( void ) : Animal() {
	this->type = "Cat";
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
	this->attr = new Brain();
}

/* Copy Costructor */
Cat::Cat(const Cat &other) : Animal(other){
	std::cout <<  GREEN <<  this->type << RESET << " Deep Copy created✔️" << std::endl; 
	this->attr = new Brain(*other.attr);
}

/* Assigment Operator */
Cat &Cat::operator=(const Cat &other){
	if(this != &other){
		Animal::operator=(other);
		if (this->attr != NULL){
			delete this->attr;
		}
		this->attr = new Brain(*other.attr);
	}
	return (*this);
}

/* Destructor */
Cat::~Cat ( void ){
	std::cout <<  GREEN <<  "Cat " << RESET << "Destructor called" << std::endl;	
	delete this->attr;
}

void Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat Say MEOW MEOW🐱🐱" << std::endl;
}
