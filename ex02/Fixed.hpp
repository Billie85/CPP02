#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed
{
	private:
		int fixed_point_number;
		const int fractional_bits;
	public:
   
		/* A member function int getRawBits( void ) const;
		that returns the raw value of the fixed-point value.
 		A member function void setRawBits( int const raw );
		that sets the raw value of the fixed-point number. */
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void)const;
		int toInt(void)const;

		//The 6 comparison operators: >, <, >=, <=, == and !=.
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		//The 4 arithmetic operators: +, -, *, and /.
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
};
#endif
