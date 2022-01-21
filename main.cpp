
import <cmath>;
#include <iostream>
#include "fractionizer.h"
import Math;
using namespace Math;
using namespace std;

Complex ComplexExp(const Complex& z) {
	return Complex(cos(z.Re()), sin(z.Re())) * Complex(pow(2.71828182845904523536, -z.Im()), 0.0);
};

Complex ComplexCos(const Complex& z) {
	Complex z_copy = z;
	return ComplexExp(z_copy) + ComplexExp(-z_copy) / Complex(2.0, 0.0);
};

Complex f(const Complex& z) {
	const Complex a = 1.0 + 0.0i;
	return a*z*z - ComplexCos(Complex(2.0, 0.0) * z);
};
Rational f(const Rational& r) {
	const Rational a = Rational(1, 1);
	const double cos_d = cos(2.0 * (double)r);
	int n, d;
	Fractionizer::fractionize(cos_d, n, d);
	return a*r*r - Rational(n, d);
};
double f(double x) {
	const double a = 1.0;
	return a*x*x - cos(2.0 * x);
};

int main()
{
	double d;
	cout << "double d = ";
	cin >> d;
	cout << "f(" << d << ") = " << f(d) << endl;
	double re, im;
	cout << "z = Re + i * Im" << endl;
	cout << "Re = ";
	cin >> re;
	cout << "Im = ";
	cin >> im;
	Complex cpx = { re, im };
	cout << "f(" << cpx << ") = " << f(cpx) << endl;
	int nom, denom;
	cout << "Type rational nominator: ";
	cin >> nom;
	cout << "Type rational denominator: ";
	cin >> denom;
	Rational rat = { nom, denom };
	cout << "f(" << rat << ") = " << f(rat) << endl;
	return 0;
}