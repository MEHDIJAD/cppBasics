#include "../incl/Ice.hpp"
#include "../incl/ICharacter.hpp"

/**
 * @brief Default constructor for Ice.
 */
Ice::Ice( void ) : AMateria("ice"){
    std::cout << BLUE << this->type << RESET
    << " Constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Ice.
 * @param other The other Ice object to copy.
 */
Ice::Ice(const Ice &other) : AMateria(other){
    std::cout << BLUE << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Ice.
 * @param other The other Ice object to assign from.
 * @return A reference to the current Ice object.
 */
Ice &Ice::operator=(const Ice &other){
    if (this != &other){
        AMateria::operator=(other);
    }
    return *this;
}

/**
 * @brief Destructor for Ice.
 */
Ice::~Ice( void ){
    std::cout << BLUE << this->type << RESET
    << " Destructor called" << std::endl;
}

/**
 * @brief Clones the Ice object.
 * @return A pointer to the cloned Ice object.
 */
AMateria *Ice::clone() const {
    return new Ice(*this);
}

/**
 * @brief Uses the Ice materia on a target character.
 * @param target The character to use the materia on.
 */
void Ice::use(ICharacter &target)
{
	std::cout  << BLUE << "* shoots an ice bolt at "
	<< RESET << target.getName()  << BLUE << " *"
	<< std::endl;
}
