#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int fixed_pointer_num; //固定小数点数値の値を格納するための整数。
	static int const fractional_bits; //端数のビット数を格納する
public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed(int store_fized_num);
	~Fixed();
};

#endif