#include "Fixed.hpp"

std::ostream &Fixed::operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

 float Fixed::toFloat(void)const//整数->少数
{
	float f = (float)this->fixed_point_number; //floatに一回渡してあげないと小数点を付けれるようになる。
	for (int i = 0; i < fractional_bits; i++)
	{
		f /= 2;
	}
	return (f);
}

int Fixed::toInt(void)const//少数->整数
{
	int i = this->fixed_point_number;
	for (int j = 0; j < fractional_bits; j++)
	{
		i *= 2;
	}
	return (i);
}

Fixed::Fixed(const Fixed &f) : position(8)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(f);
}

Fixed::Fixed(int i) : position(8)
{
	std::cout <<"Int constructor called" << std::endl;
}

Fixed::Fixed(float fl) : position(8) //少数->整数 
{
	std::cout << "Float constructor called" << std::endl;
 	for (int i = 0; i < fractional_bits; i++)
	{
		fl = fl * 2;
	}
	this->fixed_point_number = floor(fl); *///少数点以降を消すから整数の部分だけ入れてあげる。
}

Fixed::Fixed() : position(8)
{ 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
