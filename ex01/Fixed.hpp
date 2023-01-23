#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>

class Fixed
{
private:
	int fixed_point_number;
	const int fractional_bits;
public:
	float toFloat(void) const;
	int toInt( void ) const;
	Fixed();
	Fixed(int i);
	Fixed(const Fixed &f);
	Fixed(float fl);
	~Fixed();
	const Fixed &operator=(const Fixed &o)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		return(o);
	}
};

#endif