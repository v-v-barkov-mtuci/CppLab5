import Math;
#include <iostream>
using namespace Math;
using namespace std;
Complex f(const Complex& z) {
	Complex n = exp(z.Re()) * (cos(z.Arg()) + Complex(0, 1) * sin(z.Arg()));
	return  1 + 0i - z * z * z * z * z - ((n - 1) / (n + 1));
}
Rational f(const Rational& r) {
	return 1 / 1 - r * r * r * r * r - Rational(tanh((double)(r.Nominator()) / r.Denominator() / 2.0) * 100, 100);
}
double f(double x) {
	return 1.0 - x * x * x * x * x - ((exp(x) - 1) / (exp(x) + 1));
}
int main()
{
	cout << "Test complex, type with Enter:" << endl;
	int a, b;
	cin >> a >> b;
	Complex c(a, b);
	c = f(c);
	cout << c << endl;
	cout << "Test rational, type with Enter:" << endl;
	cin >> a >> b;
	Rational r = f(Rational(a, b));
	cout << r << std::endl;
	cout << "Final test:" << endl;
	double d;
	cin >> d;
	cout << f(d) << endl;
	return 0;
}
// Var 21
