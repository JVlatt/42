#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point &_other);
	Point(const float _x, const float _y);
	Point &operator=(const Point &_other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
private:
	const Fixed m_x;
	const Fixed m_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
