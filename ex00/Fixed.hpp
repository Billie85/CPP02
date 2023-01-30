#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int fixed_pointer_num;
	static int const fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &F);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	const Fixed &operator=(const Fixed &F);
};

#endif