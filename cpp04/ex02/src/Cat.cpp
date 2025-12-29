#include "../incl/Cat.hpp"

/**
 * @brief Default constructor for Cat.
 */
Cat::Cat( void ) : Animal() {
	this->type = "Cat";
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
	this->attr = new Brain();
}

/**
 * @brief Copy constructor for Cat.
 * @param other The other Cat object to copy.
 */
Cat::Cat(const Cat &other) : Animal(other){
	this->attr = new Brain(*other.attr);
	std::cout <<  GREEN <<  this->type << RESET << " Deep Copy created✔️" << std::endl; 
}

/**
 * @brief Assignment operator for Cat.
 * @param other The other Cat object to assign from.
 * @return A reference to the current Cat object.
 */
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

/**
 * @brief Destructor for Cat.
 */
Cat::~Cat ( void ){
	delete this->attr;
	std::cout <<  GREEN <<  "Cat " << RESET << "Destructor called" << std::endl;	
}

/**
 * @brief Makes the cat sound.
 */
void Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat Say MEOW MEOW🐱🐱" << std::endl;
}
