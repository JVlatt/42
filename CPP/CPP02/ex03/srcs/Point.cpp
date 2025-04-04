#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &_other) : _x(_other._x), _y(_other._y) {}

Point::Point(const float _x, const float _y) : _x(_x), _y(_y) {}

Point &Point::operator=(const Point &_other)
{
	(void)_other;
	std::cerr << "Error: Cannot assign to a Point with const members" << std::endl;
	return (*this);
}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}
