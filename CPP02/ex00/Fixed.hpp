#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _bit_buff;
	static const int _frac_bits = 8;

public:
	Fixed();							// Default constructor
	Fixed(const Fixed& f);				// Copy constructor
	Fixed& operator=(const Fixed& f);	// Copy assignment operator
	~Fixed();							// Destructor

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif