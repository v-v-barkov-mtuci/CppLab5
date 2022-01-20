import Math;
#include <iostream>
using namespace Math;

Complex ComplexExpIZ(const Complex& z)
{
	return Complex(cos(z.Re()), sin(z.Re())) * Complex(pow(2.71828182845904523536, -z.Im()), 0.0);
}
Complex ComplexSin(const Complex& z)
{
	Complex z_copy = z;
	return (ComplexExpIZ(z_copy) - ComplexExpIZ(-z_copy)) / Complex(0, 2.0);
}

Complex f(const Complex& z) {
	const Complex a = 0.0 + 1.0i;
	return 0.5 - z * ComplexSin(2 * (z - a));
}
Rational f(const Rational& r) {
	const Rational a = { 1, 2 };
	return (0.5 - (double)r + sin(2 * (((double)r) - ((double)a))));
}
double f(double x) {
	return 0.5 - x * sin(2 * x);
}

int main()
{
	std::cout << "Enter the real and imaginary parts of the complex number" << std::endl;
	int a, b;
	std::cin >> a >> b;
	Complex c(a, b);
	c = f(c);
	std::cout << c << std::endl;
	std::cout << "Enter the numerator and denominator" << std::endl;
	std::cin >> a >> b;
	Rational r = f(Rational(a, b));
	std::cout << r << std::endl;
	std::cout << "Enter a real number" << std::endl;
	double d;
	std::cin >> d;
	std::cout << f(d) << std::endl;
	return 0;
}


