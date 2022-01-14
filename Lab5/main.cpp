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
    const Complex a = 0.0 + 1.0i;
    return a + z * ComplexSin(2 * z);
}

Rational f(const Rational& r) {
    const Rational a = { 1, 2 };
    return a + r * sin(2 * (double)r);
}

double f(double x) {
    return 0.5 + x * sin(2 * x);
}

int main()
{
    std::cout << "Enter Re and Im: " << std::endl;
    int a, b;
    std::cin >> a >> b;
    Complex(a, b);
    std::cout << "f(" << a << "+" << b << "i) = " << f(Complex(a, b)) << std::endl;
    std::cout << "Enter Num and Den: " << std::endl;
    std::cin >> a >> b;
    std::cout << "f(" << a << "/" << b << ") = " << f(Rational(a, b)) << std::endl;
    std::cout << "Enter x: " << std::endl;
    double x;
    std::cin >> x;
    std::cout << "f(" << x << ") = " << f(x) << std::endl;
    return 0;
}