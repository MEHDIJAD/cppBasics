#include "incl/AMateria.hpp"
#include "incl/Ice.hpp"
#include "incl/Cure.hpp"
#include "incl/Character.hpp"

int main(void)
{
    Ice i;
    std::cout << std::endl;
    Cure j;
    std::cout << std::endl;
    
    AMateria *clone = i.clone(); 
    // clone return a pointer to AMateria, 
    // We NEED to catch it in a Var and delet it  after finish

    std::cout  << clone->getType() << std::endl;
    delete clone;

    Character c("Protagnes");



    return 0;
}
