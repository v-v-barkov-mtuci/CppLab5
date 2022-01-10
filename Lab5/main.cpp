import <cmath>;
#include <iostream>
import Math;
using namespace Math;
using namespace std;

// 8, а не 7, варик!

Complex ComplexExpIZ(const Complex& z) {
	return Complex(cos(z.Re()), sin(z.Re()))*Complex(pow(2.71828182845904523536, -z.Im()), 0.0);
};

Complex ComplexSin(const Complex& z) {
	Complex z_copy = z;
	return (ComplexExpIZ(z_copy) - ComplexExpIZ(-z_copy))/ Complex(0, 2.0);
};

Complex f(const Complex& z) {
	const Complex a = 0.0 + 1.0i;
	return a - z * ComplexSin(2.0 * z);
};
double f(const Rational& r) {
	const Rational a = { 1, 2 };
	return ((double)a) - ((double)r) * sin(2.0 * ((double)r));
};
double f(double x) {
	const double a = 0.5;
	return a-x*sin(2.0*x);
};

int main()
{
	cout << "My application" << endl;
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