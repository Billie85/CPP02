#include "Fixed.hpp"

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(f);
}

Fixed::Fixed(int i)
{
	std::cout <<"Int constructor called" << std::endl;
}

Fixed::Fixed(float fl)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed()
{ 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
