#include "../incl/Ice.hpp"

Ice::Ice( void ) : AMateria("ice"){
    std::cout << BLUE << this->type << RESET
    << " Constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other){
    std::cout << BLUE << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other){
    if (this != &other){
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice( void ){
    std::cout << BLUE << this->type << RESET
    << " Destructor called" << std::endl;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}
