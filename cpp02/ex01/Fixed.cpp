#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::FRACTIONAL_BITS = 8;

/* Default Constructor */
Fixed::Fixed( void ) : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Parametrize Constructor for INT */
Fixed::Fixed(const int decimal)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = decimal << Fixed::FRACTIONAL_BITS;

	
	// This is like decimal * 2^FRACTION_BITS
	// -> this->fixedPoint = decimal * pow(2, Fixed::FRACTIONAL_BITS);

	// OR this->fixedPoint = decimal * 256;

}

/* Parametrize Constructor for FLOAT */
Fixed::Fixed(const float real)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(real * (1 << Fixed::FRACTIONAL_BITS));
	// This is like round(real * 2^FRACTION_BITS OR * 252)
	// 1 << 8 EVAL to 256
}

/* Copy Constructor */
Fixed::Fixed(const Fixed &other) /* : fixedPoint(other.getRawBits())  */ {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


/* Assignment Operator */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		fixedPoint = other.fixedPoint;
	}
	return (*this);
}

/* Destructor */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* Set func */
void Fixed::setRawBits(int const raw){
	this->fixedPoint = raw;
}

/* Get func */
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}


float Fixed::toFloat( void ) const
{
	/*! @brief  This is like doing: 
		floatPoint = fixedPoint / 2^8(256)
		and we cast it to float so we do not lose the fraction
	*/ 
	return ((float)this->fixedPoint / (1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt( void ) const
{
	/*! @brief we do need to / 2^8(256) we can just
		shift back to the original number
	*/
	return (this->fixedPoint >> Fixed::FRACTIONAL_BITS);

	// return (this->fixedPoint / pow(2, Fixed::FRACTIONAL_BITS));
		// return (this->fixedPoint / 256);
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	/*! @brief Here we overlod the inserrtion operator 
		And return the steam as it get in (cout)	
	*/
	os << fixed.toFloat();
	return (os);
}