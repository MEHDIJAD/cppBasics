#include "../incl/Cure.hpp"
#include "../incl/ICharacter.hpp"

/**
 * @brief Default constructor for Cure.
 */
Cure::Cure( void ) : AMateria("cure"){
    std::cout << GREEN << this->type << RESET
    << " Constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Cure.
 * @param other The other Cure object to copy.
 */
Cure::Cure(const Cure &other) : AMateria(other){
    std::cout << GREEN << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Cure.
 * @param other The other Cure object to assign from.
 * @return A reference to the current Cure object.
 */
Cure &Cure::operator=(const Cure &other){
    if (this != &other){
        AMateria::operator=(other);
    }
    return *this;
}

/**
 * @brief Destructor for Cure.
 */
Cure::~Cure( void ){
    std::cout << GREEN << this->type << RESET
    << " Destructor called" << std::endl;
}

/**
 * @brief Clones the Cure object.
 * @return A pointer to the cloned Cure object.
 * @note The caller takes ownership of the returned pointer and is responsible for deleting it.
 */
AMateria *Cure::clone() const {
    return new Cure(*this);
}

/**
 * @brief Uses the Cure materia on a target character.
 * @param target The character to use the materia on.
 */
void Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals "
	<< RESET << target.getName() << GREEN << "’s wounds *"
	<< std::endl;
}
