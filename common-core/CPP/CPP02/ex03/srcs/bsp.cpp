#include "Point.hpp"
#include <iostream>

static Fixed abs(Fixed value)
{
	return (value < Fixed(0)) ? Fixed(-value.toFloat()) : value;
}

static Fixed area(Point const a, Point const b, Point const c)
{
	return abs((a.getX() * (b.getY() - c.getY()) +
				b.getX() * (c.getY() - a.getY()) +
				c.getX() * (a.getY() - b.getY())) /
			   Fixed(2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	// std::cout << "\nP.X : " << point.getX() << std::endl;
	// std::cout << "P.Y : " << point.getY() << std::endl;
	// std::cout << "Total Area : " << totalArea << std::endl;
	// std::cout << "Area PBC: " << area1 << std::endl;
	// std::cout << "Area APC: " << area2 << std::endl;
	// std::cout << "Area ABP : " << area3 << std::endl;
	if (totalArea == (area1 + area2 + area3) && area1 > Fixed(0) && area2 > Fixed(0) && area3 > Fixed(0))
		return (true);
	return (false);
}
