#include <iostream>
#include <iomanip>
#include "Colors.hpp"
#include "Point.hpp"

void testBSP(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &desc)
{
	bool result = bsp(a, b, c, p);
	std::cout << desc << ": "
			  << (result ? GREEN "INSIDE" RESET : RED "OUTSIDE" RESET)
			  << " (Point: ("
			  << std::fixed << std::setprecision(2)
			  << p.getX() << ", " << p.getY() << "))" << std::endl;
}

int main()
{
	std::cout << BRIGHT_YELLOW << "===== TEST DE LA FONCTION BSP =====" << RESET << std::endl;

	Point A(0, 0);
	Point B(10, 0);
	Point C(5, 10);

	testBSP(A, B, C, Point(5, 5), "Point au centre du triangle");
	testBSP(A, B, C, Point(1, 1), "Point proche de A mais à l'intérieur");
	testBSP(A, B, C, Point(8, 2), "Point proche de B mais à l'intérieur");
	testBSP(A, B, C, Point(5.3f, 9), "Point proche de C mais à l'intérieur");

	testBSP(A, B, C, Point(15, 5), "Point complètement en dehors du triangle");
	testBSP(A, B, C, Point(-5, 5), "Point en dehors, à gauche du triangle");

	testBSP(A, B, C, Point(5, 0), "Point sur le segment AB");
	testBSP(A, B, C, Point(2.5, 5), "Point sur le segment AC");
	testBSP(A, B, C, Point(7.5, 5), "Point sur le segment BC");

	testBSP(A, B, C, Point(0, 0), "Point au sommet A");
	testBSP(A, B, C, Point(10, 0), "Point au sommet B");
	testBSP(A, B, C, Point(5, 10), "Point au sommet C");

	return 0;
}
