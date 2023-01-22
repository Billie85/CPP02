#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>

class Fixed
{
private:
	/* data */
public:
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