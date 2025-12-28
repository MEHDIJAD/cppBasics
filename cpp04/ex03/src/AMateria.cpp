#include "../incl/AMateria.hpp"

/**
 * @brief Default constructor for AMateria.
 */
AMateria::AMateria( void ) : type(""){
    std::cout << MAGENTA << "AMateria " << RESET
    << "Private Default Constructor called" << std::endl;
}

/**
 * @brief Constructs an AMateria object with a given type.
 * @param type The type of the materia.
 */
AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << MAGENTA << "AMateria " << RESET << this->type
    << " Constructor called" << std.endl;
}

/**
 * @brief Returns the type of the materia.
 * @return A constant reference to the type of the materia.
 */
std::string const &AMateria::getType() const {
    return (this->type);   
}

/**
 * @brief Copy constructor for AMateria.
 * @param other The other AMateria object to copy.
 */
AMateria::AMateria(const AMateria &other){
    this->type = other.type;
    std::cout << MAGENTA << "AMateria " << RESET << this->type
    << " Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for AMateria.
 * @param other The other AMateria object to assign from.
 * @return A reference to the current AMateria object.
 */
AMateria &AMateria::operator=(const AMateria &other)
{
    (void)other; // While assigning a Materia to another, copying the type doesn't make sense
    return (*this);
}

/**
 * @brief Destructor for AMateria.
 */
AMateria::~AMateria ( void ){
    std::cout << MAGENTA << "AMateria " << RESET << this->type
    << " Destructor called" << std::endl;   
}

/**
 * @brief Uses the materia on a target character.
 * @param target The character to use the materia on.
 */
void AMateria::use(ICharacter &target){
	(void)target;
}
