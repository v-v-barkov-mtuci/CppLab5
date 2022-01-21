import <cmath>;
#include <iostream>
#include "fractionizer.h"
import Math;
using namespace Math;
using namespace std;


Complex f(const Complex& z) {
	const Complex a = 2.0 + 5.0i;
	return 2.2 * z * z + z - 1.0;
};
Rational f(const Rational& r) {
	const Rational a = Rational(11, 5);
	return 2.2 * r * r + r - 1.0;
};
double f(double x) {
	const double a = 2.2;
	return 2.2 * x * x + x - 1.0;
};

int main()
{
	double d;
	cout « "double d = ";
	cin » d;
	cout « "f(" « d « ") = " « f(d) « endl;
	double re, im;
	cout « "z = Re + i * Im" « endl;
	cout « "Re = ";
	cin » re;
	cout « "Im = ";
	cin » im;
	Complex cpx = { re, im };
	cout « "f(" « cpx « ") = " « f(cpx) « endl;
	int nom, denom;
	cout « "Type rational nominator: ";
	cin » nom;
	cout « "Type rational denominator: ";
	cin » denom;
	Rational rat = { nom, denom };
	cout « "f(" « rat « ") = " « f(rat) « endl;
	return 0;
}