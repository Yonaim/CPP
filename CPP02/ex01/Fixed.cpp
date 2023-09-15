#include "Fixed.hpp"

Fixed::Fixed() : _bit_buff(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_bit_buff = (n << _frac_bits);
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_bit_buff = roundf(n * (1 << _frac_bits));
    // n이 float이므로 우회적으로 shift 연산을 해야함 (2^8로 곱해주기)
    // 우회적 shift 연산의 결과 또한 float인데,
    // 정수형에 이를 저장해야하므로 소수점 아래까지 최대한 보존하기 위해 반올림한다.
}

Fixed::Fixed(const Fixed &f) : _bit_buff(f.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->_bit_buff = f.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// -----------------------------------------------------------------------------

// overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed_num)
{
    return (out << fixed_num.toFloat());
    // ostream 객체의 << 연산자 반환형은 ostream 객체 그 자체이므로 연산 결과를 바로 리턴하면 된다.
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
    // 소수부를 보존하기 위해 먼저 float로 형변환 후 우회적 shift 연산
}

int Fixed::toInt(void) const
{
    return (roundf(this->toFloat()));
}