#include "Fixed.hpp"

int		main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Value of a:   " << a << " \t (float)" << std::endl;
	std::cout << "Value of b:   " << b << " \t (int)" << std::endl;
	std::cout << "Value of c:   " << c << " \t (float)" << std::endl;
	std::cout << "Value of d:   " << d << " \t (int)" << std::endl;

	std::cout << "------------------INT------------------" << std::endl;

	std::cout << "Value of a: " << a.toInt() << " \t (int)" << std::endl;
	std::cout << "Value of c: " << c.toInt() << " \t (int)" << std::endl;
	std::cout << "Value of d: " << d.toInt() << " \t (int)" << std::endl;
	std::cout << "Value of b: " << b.toInt() << " \t (int)" << std::endl;

	std::cout << "-----------------FLOAT-----------------" << std::endl;

	std::cout << "Value of a: " << a.toFloat() << " \t (float)" << std::endl;
	std::cout << "Value of b: " << b.toFloat() << " \t (float)" << std::endl;
	std::cout << "Value of c: " << c.toFloat() << " \t (float)" << std::endl;
	std::cout << "Value of d: " << d.toFloat() << " \t (float)" << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	return (0);
}