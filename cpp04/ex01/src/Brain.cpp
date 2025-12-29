#include "../incl/Brain.hpp"

/**
 * @brief Default constructor for Brain.
 */
Brain::Brain( void ){
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "Basic Idea"; 
	}
	std::cout << GRAY << "Brain Constructor called"
	<< RESET << std::endl;
}

/**
 * @brief Copy constructor for Brain.
 * @param other The other Brain object to copy.
 */
Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++){
		this->ideas[i] = other.ideas[i];
	}
	std::cout << GRAY << "Brain Copy Constructor called"
	<< RESET << std::endl;
}

/**
 * @brief Assignment operator for Brain.
 * @param other The other Brain object to assign from.
 * @return A reference to the current Brain object.
 */
Brain &Brain::operator=(const Brain &other)
{
	if(this != &other)
	{
		for (size_t i = 0; i < 100; i++){
		this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

/**
 * @brief Destructor for Brain.
 */
Brain::~Brain( void ){
	std::cout << GRAY << "Brain Destructor called" << RESET << std::endl;
}

const std::string& Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return this->ideas[0]; // Safety fallback
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}
