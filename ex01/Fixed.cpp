#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPointValue = copy.getRawBits();
	return *this;
}

Fixed::Fixed(const int fixedPointInt)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = fixedPointInt << this->_fractionalBits;
}

Fixed::Fixed(const float fixedPointFloat)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(fixedPointFloat * (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}