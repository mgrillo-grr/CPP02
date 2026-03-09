#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int		main(void)
{
	Point	a(6.5f, 6.5f);
	Point	b(8.70447f, 3.48655f);
	Point	c(3.50566f, 7.08651f);
	Point	point(5.93419f, 6.08597f);

	if (bsp(a, b, c, point) == true)
		std::cout << "Point IS INSIDE the triangle." << std::endl;
	else
		std::cout << "Point IS NOT INSIDE the triangle." << std::endl;

	return (0);
}