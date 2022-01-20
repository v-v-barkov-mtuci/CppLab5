import <cmath>;
#include <iostream>
import Math;
using namespace Math;
using namespace std;


Complex f(const Complex& z)
{
	const Complex a = 2.0 + 5.0i;
	return 2.2 * z * z + z - 1.0;
}
double f(const Rational& r)
{
	const Rational a = { 11, 5 };
	return (2.2 * ((double)r) * ((double)r) + ((double)r) - 1.0);
}
double f(double x)
{
	const double a = 2.2;
	return 2.2 * x * x + x - 1.0;
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