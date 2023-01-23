#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed //staticがないからFixedクラスを作った瞬間に呼ばれる。
{
	private:
		int fixed_point_number;
		const int fractional_bits;
	public:
		float toFloat(void)const;
		int toInt(void)const;
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
std::ostream &operator<<(std::ostream &os, const Fixed &f);
#endif
