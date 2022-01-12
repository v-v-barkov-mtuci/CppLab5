import <cmath>;
#include <iostream>
import Math;
using namespace Math;
using namespace std;

Complex ComplexExpIZ(const Complex& z)
{
	return Complex(cos(z.Re()), sin(z.Re())) * Complex(pow(2.71828182845904523536, -z.Im()), 0.0);
}
Complex ComplexSin(const Complex& z)
{
	Complex z_copy = z;
	return (ComplexExpIZ(z_copy) - ComplexExpIZ(-z_copy)) / Complex(0, 2.0);
}
Complex f(const Complex& z)
{
	const Complex a = 0.0 + 1.0i;
	return 2.0 * z + ComplexSin(z - a);
}
double f(const Rational& r)
{
	const Rational a = { 1, 2 };
	return (2.0 * ((double)r) + sin(((double)r) - ((double)a)));
}
double f(double x)
{
	const double a = 0.5;
	return 2 * x + sin(x - a);
}

int main()
{
	setlocale(LC_ALL, "Ru");

	cout << "¬ведите вещественное значение: ";
	double d;
	cin >> d;
	cout << "f(" << d << ") = " << f(d) << endl;
	double re, im;
	cout << "¬ведите реальную часть комплексного числа: ";
	cin >> re;
	cout << "¬ведите мнимую часть комплексного числа: ";
	cin >> im;
	Complex cpx = { re, im };
	cout << "f(" << cpx << ") = " << f(cpx) << endl;
	int nom, denom;
	cout << "¬ведите числитель дроби: ";
	cin >> nom;
	cout << "¬ведите знаменатель дроби: ";
	cin >> denom;
	Rational rat = { nom, denom };
	cout << "f(" << rat << ") = " << f(rat) << endl;

	return 0;
}