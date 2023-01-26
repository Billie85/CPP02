#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &other)
{
	this->fixed_point_number = other.getRawBits();
	return (*this);
}

// -------- set and get ----------
int Fixed::getRawBits(void) const
{
	return(this->fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

// -------- toFloat Tont function --------
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
	for (int j = 0; j < this->fractional_bits; j++)
	{
		i /= 2;
	}
	return (i);
}

// -------- constructor --------
Fixed::Fixed() :fractional_bits(8)
{
	this->fixed_point_number = 0;
}

Fixed::Fixed(int i) :fractional_bits(8)
{
	this->fixed_point_number = i << this->fractional_bits;
}

Fixed::Fixed(const Fixed &f) :fractional_bits(8)
{
	*this = f; //copy the value to a ponter 
}

Fixed::Fixed(float fl) :fractional_bits(8)//少数->整数
{
	for (int i = 0; i < this->fractional_bits; i++)
	{
		fl = fl * 2;
	}
	this->fixed_point_number = roundf(fl);
}

// -----The 6 comparison operators: >, <, >=, <=, == and != -----
bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

// -----The 4 arithmetic operators: +, -, *, and /. -----

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed r(this->toFloat() + other.toFloat());
	return (r);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed r(this->toFloat() - other.toFloat());
	return (r);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed r(this->toFloat() * other.toFloat());
	return (r);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed r(this->toFloat() / other.toFloat());
	return (r);
}

// ------------increment--------------
Fixed &Fixed::operator++(void)
{
	++this->fixed_point_number;
	return(*this);
}

Fixed &Fixed::operator--(void)
{
	--this->fixed_point_number;
	return(*this);
}

Fixed Fixed::operator++(int i)
{
	Fixed f = *this;
	++(this->fixed_point_number);
	return(f);
}

Fixed Fixed::operator--(int i)
{
	Fixed f = *this;
	--(this->fixed_point_number);
	return(f);
}

std::ostream &operator<< (std::ostream &os, Fixed const f)
{
	os << f.toFloat();
	return (os);
}

static const Fixed &min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

static const Fixed &max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

static  Fixed &min( Fixed &a,  Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

static  Fixed &max( Fixed &a,  Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed::~Fixed(void){
}