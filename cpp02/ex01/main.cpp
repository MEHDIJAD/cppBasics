#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	// Default constructor called
	Fixed const b( 10 );
	// Int constructor called
	Fixed const c( 42.42f );
	// Float constructor called
	Fixed const d( b );
	// Copy constructor called
	// Copy assignment operator called

	a = Fixed( 1234.4321f );
	// Float constructor called
	// Copy assignment operator called
	// Destructor called
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return (0);
}
