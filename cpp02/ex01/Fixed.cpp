#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed( void ) : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) /* : fixedPoint(other.getRawBits())  */ {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		fixedPoint = other.fixedPoint;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw){
	this->fixedPoint = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}


Fixed::Fixed(const int decimal)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = decimal << Fixed::FRACTIONAL_BITS;
	// This is like decimal * 2^FRACTION_BITS

}

Fixed::Fixed(const float real)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(real * (1 << Fixed::FRACTIONAL_BITS));
	// This is like round(real * 2^FRACTION_BITS OR * 252)
	// 1 << 8 EVAL to 256
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixedPoint / (1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt( void ) const
{
	return (this->fixedPoint >> Fixed::FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}