#include "Fixed.hpp"

const Fixed &Fixed::operator=(const Fixed &o)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_number = o.getRawBits();
	return(*this);
}

int Fixed::getRawBits(void) const
{
	return(this->fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

//Default constructor
Fixed::Fixed(void) : fractional_bits(8)
{ 
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

//Copy constructor
Fixed::Fixed( Fixed const &f) :fractional_bits(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

//int constructor
Fixed::Fixed(int i) :fractional_bits(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = i << this->fractional_bits; //?
}

//Float constructor
Fixed::Fixed(float fl) :fractional_bits(8) //少数->整数
{
	std::cout << "Float constructor called" << std::endl;
 	for (int i = 0; i < this->fractional_bits; i++)
	{
		fl = fl * 2;
	}
	this->fixed_point_number = roundf(fl);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

 float Fixed::toFloat(void)const//整数->少数
{
	float f = this->fixed_point_number;
	for (int i = 0; i < this->fractional_bits; i++)
	{
		f /= 2;
	}
	return (f);
}

int Fixed::toInt(void)const//少数->整数
{
	int i = this->fixed_point_number;
	for (int j = 0; j < this->fractional_bits; j++)
	{
		i /= 2;
	}
	return (i);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}