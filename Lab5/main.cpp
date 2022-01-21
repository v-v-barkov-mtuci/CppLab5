import <cmath>;
#include <iostream>
#include "fractionizer.h"
import Math;
using namespace Math;
using namespace std;

Complex ComplexExpIZ(const Complex& z) {
	return Complex(cos(z.Re()), sin(z.Re()))*Complex(pow(2.71828182845904523536, -z.Im()), 0.0);
};

Complex ComplexSin(const Complex& z) {
	Complex z_copy = z;
	auto delta = ComplexExpIZ(z_copy) - ComplexExpIZ(-z_copy);
	return delta/ Complex(0, 2.0);
};

Complex f(const Complex& z) {
	const Complex a = 0.0 + 1.0i;
	return a - z * ComplexSin(Complex(2.0, 0.0) * z);
};

Rational f(const Rational& r) {
	const Rational a = Rational(1, 2);
	const double r_d = (double) r;
	const double result = sin(2.0 * r_d);
	int n, d, sign;
	sign = (result >= 0) ? 1 : -1;
	Fractionizer::fractionize(abs(result), n, d);
	Rational addable = Rational(n * sign, d);
	Rational ret = a - (r*addable);
	return ret;
};
double f(double x) {
	const double a = 0.5;
	return a-x*sin(2.0*x);
};

int main()
{
	cout << "My application" << endl;
	cout << "Includes Fractionizer ( https://github.com/ajneu/fractionizer )" << endl;
	cout << "Type double value: ";
	double d;
	cin >> d;
	cout << "f(" << d << ") = " << f(d) << endl;
	double re, im;
	cout << "Type complex value real part: ";
	cin >> re;
	cout << "Type complex value imaginary part: ";
	cin >> im;
	Complex cpx = { re, im };
	cout << "f(" << cpx << ") = " << f(cpx) << endl;
	int nom, denom;
	cout << "Type rational nominator: ";
	cin >> nom;
	cout << "Type rational denominator: ";
	cin >> denom;
	Rational rat = {nom, denom};
	cout << "f(" << rat << ") = " << f(rat) << endl;
	return 0;
}