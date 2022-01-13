#include <iostream>
import Math;
using namespace Math;


const double PI = acos(-1.0);

Complex ComplexExp(const Complex& z)
{
    return Complex(cos(z.Re()), sin(z.Re())) * Complex(pow(PI, -z.Im()), 0);
}
Complex ComplexSin(const Complex& z)
{
    Complex tmpZ = z;
    return (ComplexExp(tmpZ) - ComplexExp(-tmpZ)) / Complex(0, 2);
}

Complex f(const Complex& z) {
    const Complex a = 2.0 + 5i;
    return 3 / 7 + (5 / 11) * z - a / z;
}

Rational f(const Rational& r) {
    const Rational a = { 5, 2 };
    return 3 / 7 + (5 / 11) * r - a / r;
}

double f(double x) {
    return 3 / 7 + (5 / 11) * x - 2.5 / x;
}

int main()
{
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