import Math;
#include <iostream>
using namespace Math;

Complex f(const Complex& z) {
	return 2 * z + (1 + 10i) / z;
}
Rational f(const Rational& r) {
	return 2 * r + (13 / 10) / r;
}
double f(double x) {
	return 2 * x + 0.2 / x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Enter real and imaginary parts of a complex number" << std::endl;
	int a, b;
	std::cin >> a >> b;
	Complex c(a, b);
	c = f(c);
	std::cout << c << std::endl;
	std::cout << "Enter numerator and denominator" << std::endl;
	std::cin >> a >> b;
	Rational r = f(Rational(a, b));
	std::cout << r << std::endl;
	std::cout << "Enter a real number" << std::endl;
	double d;
	std::cin >> d;
	std::cout << f(d) << std::endl;
	return 0;
}


