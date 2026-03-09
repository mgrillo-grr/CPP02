#include "Point.hpp"

static float	bspArea(Point const a, Point const b, Point const c)
{
	return (
		(std::fabs(
		(a.getX() * (b.getY() - c.getY())) +
		(b.getX() * (c.getY() - a.getY())) +
		(c.getX() * (a.getY() - b.getY())))
		) / 2
	);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float areaABC = bspArea(a, b, c);
	float areaABP = bspArea(a, b, point);
	float areaBCP = bspArea(point, b, c);
	float areaCAP = bspArea(a, point, c);

	if (!areaABP || !areaBCP || !areaCAP)
		return (false);
	return (areaABC == (areaABP + areaBCP + areaCAP));
}
