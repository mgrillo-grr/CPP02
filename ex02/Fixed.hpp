#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		static const int _fractionalBits;
		int		_fixedPointValue;

	public:
		// CONSTRUCTORS
		Fixed();
		Fixed(const int fixedPointInt);
		Fixed(const float fixedPointFloat);
		Fixed(const Fixed &other);

		// DESTRUCTOR
		~Fixed();

		// GETTER - SETTER
		void	setRawBits(int const raw);
		int		getRawBits(void) const;

		//OVERLOAD EQUALS OPERATOR
		Fixed &operator=(const Fixed &other);

		// OVERLOAD COMPARISON OPERATORS
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// OVERLOAD ARITHMETIC OPERATORS
		float	operator+(const Fixed &other) const;
		float	operator-(const Fixed &other) const;
		float	operator*(const Fixed &other) const;
		float	operator/(const Fixed &other) const;

		// OVERLOAD PRE INCREMENT/DECREMENT OPERATORS
		Fixed		operator++();
		Fixed		operator--();
		Fixed		operator++(int);
		Fixed		operator--(int);

		// PUBLIC METHODS COMPARISONS
		static Fixed		&min(Fixed &first, Fixed &second);
		static Fixed 		&max(Fixed &first, Fixed &second);
		static const Fixed	&min(Fixed const &first, Fixed const &second);
		static const Fixed 	&max(Fixed const &first, Fixed const &second);

		// PUBLIC METHODS CONVERSIONS
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed);

#endif