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
    Fixed(const int n);               // Int constructor
    Fixed(const float n);             // Float constructor
    Fixed(const Fixed &f);            // Copy constructor
    Fixed &operator=(const Fixed &f); // Copy assignment operator
    ~Fixed();                         // Destructor

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

// overload of the insertion (<<) operator
// 다른 클래스 std::ostream과의 연산이므로, Fixed 클래스 내부 멤버 함수로 선언하면 안됨
std::ostream &operator<<(std::ostream &out, const Fixed &fixed_num);

#endif