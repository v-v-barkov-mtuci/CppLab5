#include <iostream>

import Math;
using namespace Math;

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b = 0;

	std::cout << "������� �������� � ������ �������� ������������ �����: " << std::endl;
	std::cin >> a >> b;
	Complex complexF = f(Complex(a, b));

	std::cout << "������� ��������� � ����������� ������������ �����: " << std::endl;
	std::cin >> a >> b;
	Rational rationalF = f(Rational(a, b));

	std::cout << "������� ����� �����: " << std::endl;
	std::cin >> a;
	double doubleF = f(double(a));

	std::cout << "Complex: " << complexF << std::endl;
	std::cout << "Rational: " << rationalF << std::endl;
	std::cout << "double: " << doubleF << std::endl;

	return 0;
}