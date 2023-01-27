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
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void)const;
		int toInt(void)const;

		const Fixed &operator=(const Fixed &o);
		Fixed();
		Fixed(int i);
		Fixed(const Fixed &f);
		Fixed(float fl);
		~Fixed();
};
std::ostream &operator<<(std::ostream &os, const Fixed &f);
#endif
