#include "Fixed.hpp"
#include <exception>

Fixed::Fixed() : _bit_buff(0)
{
}

Fixed::Fixed(const int n)
{
    this->_bit_buff = (n << _frac_bits);
}

Fixed::Fixed(const float n)
{
    this->_bit_buff = roundf(n * (1 << _frac_bits));
}

Fixed::Fixed(const Fixed &ori) : _bit_buff(ori.getRawBits())
{
}

Fixed &Fixed::operator=(const Fixed &ori)
{
    if (this != &ori)
        this->_bit_buff = ori.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

// -----------------------------------------------------------------------------

int Fixed::getRawBits() const
{
    return (this->_bit_buff);
}

void Fixed::setRawBits(int const raw)
{
    this->_bit_buff = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_bit_buff / (1 << _frac_bits));
}

int Fixed::toInt(void) const
{
    return (roundf(this->toFloat()));
}

// -------------------------- Operator overriding ------------------------------

// insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed_num)
{
    return (out << fixed_num.toFloat());
}

// comparison operators
bool Fixed::operator>(const Fixed &cmp) const
{
    return (this->_bit_buff > cmp.getRawBits());
}

bool Fixed::operator<(const Fixed &cmp) const
{
    return (this->_bit_buff < cmp.getRawBits());
}

bool Fixed::operator>=(const Fixed &cmp) const
{
    return (this->_bit_buff >= cmp.getRawBits());
}

bool Fixed::operator<=(const Fixed &cmp) const
{
    return (this->_bit_buff <= cmp.getRawBits());
}

bool Fixed::operator==(const Fixed &cmp) const
{
    return (this->_bit_buff == cmp.getRawBits());
}

bool Fixed::operator!=(const Fixed &cmp) const
{
    return (this->_bit_buff != cmp.getRawBits());
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed &opd)
{
    Fixed ret(this->toFloat() + opd.toFloat());
    return (ret);
}

Fixed Fixed::operator-(const Fixed &opd)
{
    Fixed ret(this->toFloat() - opd.toFloat());
    return (ret);
}

Fixed Fixed::operator*(const Fixed &opd)
{
    Fixed ret(this->toFloat() * opd.toFloat());
    return (ret);
}

Fixed Fixed::operator/(const Fixed &opd)
{
    if (opd._bit_buff == 0)
        throw(std::runtime_error("Divide by zero"));
    Fixed ret(this->toFloat() / opd.toFloat());
    return (ret);
}

// increment & decrement operators
Fixed &Fixed::operator++(void)
{
    ++this->_bit_buff;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    --this->_bit_buff;
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    const Fixed tmp(*this);
    ++this->_bit_buff;
    return (tmp);
}

const Fixed Fixed::operator--(int)
{
    const Fixed tmp(*this);
    --this->_bit_buff;
    return (tmp);
}

// -----------------------------------------------------------------------------

// compare and return
Fixed &Fixed::min(Fixed &cmp1, Fixed &cmp2)
{
    if (cmp1._bit_buff < cmp2._bit_buff)
        return (cmp1);
    else
        return (cmp2);
}

Fixed &Fixed::max(Fixed &cmp1, Fixed &cmp2)
{
    if (cmp1._bit_buff > cmp2._bit_buff)
        return (cmp1);
    else
        return (cmp2);
}

const Fixed &Fixed::min(const Fixed &cmp1, const Fixed &cmp2)
{
    if (cmp1._bit_buff < cmp2._bit_buff)
        return (cmp1);
    else
        return (cmp2);
}

const Fixed &Fixed::max(const Fixed &cmp1, const Fixed &cmp2)
{
    if (cmp1._bit_buff > cmp2._bit_buff)
        return (cmp1);
    else
        return (cmp2);
}
