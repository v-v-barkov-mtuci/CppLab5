import Math;
#include <iostream>
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
Complex ComplexCos(const Complex& z)
{
    Complex tmpZ = z;
    return (ComplexExp(tmpZ) + ComplexExp(-tmpZ)) / Complex(0, 2);
}

Complex f(const Complex& z) {
    const Complex a = 2.0 + 0i;
    return a+z*(ComplexSin(z) / ComplexCos(z));
}

Rational f(const Rational& r) {
    const Rational a = { 2,1 };
    return a + r * tan((double)r);
}

double f(double x) {
    return 2.0 + x * tan(x);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "¬ведите действительную и мнимую части комплексного числа" << std::endl;
    int a, b;
    std::cin >> a >> b;
    Complex c(a, b);
    c = f(c);
    std::cout << c << std::endl;
    std::cout << "¬ведите числитель и знаменатель" << std::endl;
    std::cin >> a >> b;
    Rational r = f(Rational(a, b));
    std::cout << r << std::endl;
    std::cout << "¬ведите реальное число" << std::endl;
    double d;
    std::cin >> d;
    std::cout << f(d) << std::endl;
    return 0;
}