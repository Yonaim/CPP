#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
  private:
    int _bit_buff;
    static const int _frac_bits = 8;

  public:
    Fixed();                          // Default constructor
    Fixed(const int n);              
    Fixed(const float n);            
    Fixed(const Fixed &f);            // Copy constructor
    Fixed &operator=(const Fixed &f); // Copy assignment operator
    ~Fixed();                         // Destructor

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    // comparison operators
    bool operator>(const Fixed &cmp) const;
    bool operator<(const Fixed &cmp) const;
    bool operator>=(const Fixed &cmp) const;
    bool operator<=(const Fixed &cmp) const;
    bool operator==(const Fixed &cmp) const;
    bool operator!=(const Fixed &cmp) const;

    // arithmetic operators
    Fixed operator+(const Fixed &opd);
    Fixed operator-(const Fixed &opd);
    Fixed operator*(const Fixed &opd);
    Fixed operator/(const Fixed &opd);

    // increment & decrement operators
    Fixed &operator++(void);
    Fixed &operator--(void);
    const Fixed operator++(int);
    const Fixed operator--(int);

    // compare and return
    static Fixed &min(Fixed &cmp1, Fixed &cmp2);
    static Fixed &max(Fixed &cmp1, Fixed &cmp2);
    static const Fixed &min(const Fixed &cmp1, const Fixed &cmp2);
    static const Fixed &max(const Fixed &cmp1, const Fixed &cmp2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_num);

#endif