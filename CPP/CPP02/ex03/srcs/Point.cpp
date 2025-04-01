#include "Point.hpp"
#include <iostream>

Point::Point() : m_x(0), m_y(0) {}

Point::Point(const Point &_other) : m_x(_other.m_x), m_y(_other.m_y) {}

Point::Point(const float _x, const float _y) : m_x(_x), m_y(_y) {}

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
	return (m_x);
}

Fixed Point::getY() const
{
	return (m_y);
}
