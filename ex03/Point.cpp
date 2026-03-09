#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::~Point() {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point&	Point::operator=(const Point &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

const Fixed		&Point::getX(void) const {
	return (this->_x);
}

const Fixed		&Point::getY(void) const {
	return (this->_y);
}
