#include "Fixed.hpp"


int Fixed::getRawBits(void) const
{
	return(this->fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

float Fixed::toFloat(void)const //整数->少数
{
	float f = this->fixed_point_number;
	for (int i = 0; i < this->fractional_bits; i++)
	{
		f /= 2;
	}
	return (f);
}

int Fixed::toInt(void)const //少数->整数
{
	int i = this->fixed_point_number;
	for (int j = 0; j < count; j++)
	{
		i /= 2;
	}
	return (i);
}