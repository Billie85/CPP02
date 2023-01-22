#include "Fixed.hpp"

Fixed::Fixed(int fixed_pointer_num)
{
	fixed_pointer_num = 0;
}

Fixed::~Fixed()
{}

void setRawBits(int const raw)
{
	this->fixed_pointer_num = raw;
}

int getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_pointer_num);
}