#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// ANSI Color Codes
#define CYAN    "\033[36m"

class FragTrap : public ClapTrap
{
	public:
		/* Default Constructor */
		FragTrap( void );
		/* Parameterized Constructor */
		FragTrap( std::string name );
		/* Copy Constructor */
		FragTrap( const FragTrap &other );
		/* Assignment Operator */
		FragTrap &operator=( const FragTrap &other );
		/* Destructor */
		~FragTrap( void );

		void attack( const std::string& target );
		void highFivesGuys( void );
};

#endif
