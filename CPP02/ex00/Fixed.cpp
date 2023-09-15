#include "Fixed.hpp"

Fixed::Fixed() : _bit_buff(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;

    this->_bit_buff = f.getRawBits();
    // *this = f; // 전체를 복사한다는 의미에서 이렇게 쓸 수도 있다

    // 복사에는 값을 그대로 복사하는 얕은 복사(Shallow Copy)와
    // 해당 주소가 가리키는 값을 재할당하여 그 주소를 갖게하는 깊은 복사(Deep Copy)가 있는데,
    // 이 클래스에는 할당된 메모리 영역의 '주소'를 갖는 데이터 멤버(이를테면 포인터)가 없으므로
    // 깊은 복사를 할 수 있는 여지가 없다. 그냥 동일한 값을 대입만 하면 된다.
}

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &f)
        return (*this);
    // 만약 같은 인스턴스라면 불필요한 자기 할당(self-assignment)를 하게 되므로,
    // 이 경우에는 아무것도 하지 않고 그대로 리턴함
    this->_bit_buff = f.getRawBits();
    return (*this);
    // this는 포인터이므로, 레퍼런스를 반환하기 위해서는 역참조(*)를 한번 해주어야함
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_bit_buff);
}

void Fixed::setRawBits(int const raw)
{
    this->_bit_buff = raw;
}