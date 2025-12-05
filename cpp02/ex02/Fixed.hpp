// #pragma once
#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <ostream>
class Fixed
{
	private:
		int fixedPoint;
		static const int FRACTIONAL_BITS;
	public:
		/* Default Constructor */
		Fixed( void );

		/*! @brief Parametrize Constructor for INT
		converts @param decimal to the corresponding fixed-point value
		*/
		Fixed(const int decimal);

		/*! @brief Parametrize Constructor for FLOAT
		converts @param real to the corresponding fixed-point value
		*/
		Fixed(const float real);
		/* Copy Constructor */
		Fixed(const Fixed &other);
		/* Assignment Operator */
		Fixed &operator=(const Fixed &other);
		/* Destructor */
		~Fixed();

		int getRawBits( void ) const ;
		void setRawBits( int const raw );

		/*! @brief converts the fixed-point value to a floating-point value.*/
		float toFloat( void ) const;

		/*! @brief converts the fixed-point value to an integer value*/
		int toInt( void ) const;	
};
	
/* Overloading the inserrtion operator (<<)*/
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);


#endif
