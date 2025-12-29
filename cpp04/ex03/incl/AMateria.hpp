#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"

class ICharacter; //* Forward declaration

class AMateria
{
	private:
		/*! 
         * @note The subject requires a Parameterized Constructor, but Orthodox Canonical Form
         * requires a Default Constructor. We make it private so it exists (to satisfy the rule),
         * but cannot be called publicly, preventing the creation of a "typeless" AMateria.
         */
		AMateria( void );
	protected:
		std::string type;
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria( void );
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
