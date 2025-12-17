#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


class ClapTrap
{
	private:

	protected:
		std::string _Name;
		unsigned int _HitPoint;
		unsigned int _EnergyPoint;
		unsigned int _AttackDamage;

	public:
		/* Default Constructor */
		ClapTrap( void );
		/* Parametrize Constructor (REQ) */
		ClapTrap(std::string Name);
		/* Copy Costructor */
		ClapTrap(const ClapTrap &other);
		/* Assigment Operator */
		ClapTrap &operator=(const ClapTrap &other);
		/* Destorctor */
		~ClapTrap( void );

		/* Setter Func */
		void setName(std::string const Name);
		/* Getter Func */
		std::string getName( void ) const;
		unsigned int getHitPoints( void ) const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


};

#endif
