#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
  private:
    const Fixed _x;
    const Fixed _y;

  public:
    Point();                            // Default constructor
    Point(const Fixed x, const Fixed y);
    Point(const Point &ori);            // Copy constructor
    Point &operator=(const Point &ori); // Copy assignment operator
    ~Point();                           // Destructor

    float getX() const;
    float getY() const;
};

typedef Point Vector;

float operator*(Vector const &v1, Vector const &v2);
float ccw(Point const &p1, Point const &p2, Point const &p3);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif