#include "Fixed.hpp"

Fixed::Fixed(int store_fized_num)
{
	store_fized_num = 0;
}

Fixed::~Fixed()
{

}

void setRawBits(int const raw)
{
	this->fixed_pointer_num = raw;
}

int getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_pointer_num);
}