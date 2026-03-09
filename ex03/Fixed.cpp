#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int fixedPointInt) {
	this->_fixedPointValue = fixedPointInt << this->_fractionalBits;
}

Fixed::Fixed(const float fixedPointFloat) {
	this->_fixedPointValue = roundf(fixedPointFloat * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::~Fixed() {}

//-------------------------------------------------------------------------
//----------------------------------------------------------GETTER & SETTER

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

int		Fixed::getRawBits(void) const {
	return (this->_fixedPointValue);
}

//-------------------------------------------------------------------------
//--------------------------------------------OVERLOAD EQUALS OPERATORS

Fixed&	Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

//-------------------------------------------------------------------------
//--------------------------------------------OVERLOAD COMPARISON OPERATORS

bool	Fixed::operator>(const Fixed &other) const {
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->toFloat() != other.toFloat());
}

//-------------------------------------------------------------------------
//--------------------------------------------OVERLOAD ARITHMETIC OPERATORS

float	Fixed::operator+(const Fixed &other) const {
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed &other) const {
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed &other) const {
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed &other) const {
	return (this->toFloat() / other.toFloat());
}

//-------------------------------------------------------------------------
//--------------------------------OVERLOAD PRE/POS INCREMENT/DECREMENT OPERATORS

Fixed		Fixed::operator++() {
	this->_fixedPointValue++;
	return (*this);
}

Fixed		Fixed::operator--() {
	this->_fixedPointValue--;
	return (*this);
}

Fixed		Fixed::operator++(int) {
	Fixed	temp = *this;
	++this->_fixedPointValue;
	return (temp);
}

Fixed		Fixed::operator--(int) {
	Fixed	temp = *this;
	--this->_fixedPointValue;
	return (temp);
}

//-------------------------------------------------------------------------
//-----------------------------------------------------PUBLIC METHODS MIN/MAX

Fixed	&Fixed::min(Fixed &first, Fixed &second) {
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second) {
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

const Fixed 	&Fixed::min(Fixed const &first, Fixed const &second) {
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

const Fixed	&Fixed::max(Fixed const &first, Fixed const &second) {
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

//-------------------------------------------------------------------------
//---------------------------------------------PUBLIC METHODS toFloat/toInt

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

//-------------------------------------------------------------------------
//----------------------------------------------------------PUBLIC FUNCTION

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed) {
	str << fixed.toFloat();
	return (str);
}