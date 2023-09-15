#include "Point.hpp"

Point::Point()
{
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
}

Point::Point(const Point &ori) : _x(ori._x), _y(ori._y)
{
}

Point &Point::operator=(const Point &ori)
{
    if (this != &ori)
    {
        const_cast<Fixed &>(this->_x) = ori.getX();
        const_cast<Fixed &>(this->_y) = ori.getY();
    }
    return (*this);
}

Point::~Point()
{
}

float Point::getX() const
{
    return (this->_x.toFloat());
}

float Point::getY() const
{
    return (this->_y.toFloat());
}
