#include "../incl/WrongAnimal.hpp"

/**
 * @brief Default constructor for WrongAnimal.
 */
WrongAnimal::WrongAnimal(void) : type("")
{
    std::cout << YELLOW << "WrongAnimal " << RESET << "Constructor called"
    << std::endl;
}

/**
 * @brief Constructs a WrongAnimal object with a given type.
 * @param type The type of the wrong animal.
 */
WrongAnimal::WrongAnimal(std::string &type) : type(type)
{
    std::cout << YELLOW << "WrongAnimal " << this->type << RESET
              << " Constructor called" << std::endl;
}

/**
 * @brief Copy constructor for WrongAnimal.
 * @param other The other WrongAnimal object to copy.
 */
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << YELLOW << "WrongAnimal " << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for WrongAnimal.
 * @param other The other WrongAnimal object to assign from.
 * @return A reference to the current WrongAnimal object.
 */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other){
        this->type = other.type;
    }
    return (*this);
}

/**
 * @brief Destructor for WrongAnimal.
 */
WrongAnimal::~WrongAnimal(void)
{
    std::cout << YELLOW << "WrongAnimal " << this->type << RESET
    << " Destructor called" << std::endl;
}

/**
 * @brief Returns the type of the wrong animal.
 * @return The type of the wrong animal.
 */
std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

/**
 * @brief Makes the wrong animal sound.
 */
void WrongAnimal::makeSound( void ) const {
    std::cout << RED << "WrongAnimal Say WRONG SOUND ❌" << std::endl;
}