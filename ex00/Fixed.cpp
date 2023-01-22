#include "Fixed.hpp"

// A default constructor that initializes 
//the fixed-point number value to 0.

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed()
{
	this->fixed_pointer_num = 0; 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& F)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(F);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_pointer_num = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_pointer_num);
}