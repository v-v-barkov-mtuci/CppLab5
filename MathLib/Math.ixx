export module Math;
import <cmath>;
import <string_view>;
import <iostream>;

export namespace Math
{
	class Complex
	{
		double r;
		double phi;
		void DeltaRe(const double delta);
	public:
		Complex();
		Complex(double i);
		Complex(double re, double im);

		static Complex FromAlgebraicForm(double re, double im);
		static Complex FromExponentialForm(double m, double a);

		double Re() const;
		double Im() const;
		double Mod() const;
		double Arg() const;

		explicit operator double() const;

		Complex operator-();
		Complex& operator++();
		Complex operator++(int);
		Complex& operator--();
		Complex operator--(int);

		Complex& operator+=(const Complex& left);
		Complex& operator-=(const Complex& left);
		Complex& operator*=(const Complex& left);
		Complex& operator/=(const Complex& left);
	};
	Complex operator + (const Complex& left, const Complex& right);
	Complex operator - (const Complex& left, const Complex& right);
	Complex operator * (const Complex& left, const Complex& right);
	Complex operator / (const Complex& left, const Complex& right);

	Complex operator "" i(long double x);

	std::ostream& operator<< (std::ostream& stream, const Complex& complex);


	class Rational
	{
		int nominator;
		int denominator;
	public:
		Rational();
		Rational(int n, int d);
		Rational(int n);

		int Nominator() const;
		int Denominator() const;

		explicit operator double() const;

		Rational operator - ();
		Rational& operator++();
		Rational operator++(int);
		Rational& operator--();
		Rational operator--(int);

		bool operator ==(Rational x);
		bool operator !=(Rational x);
#if 0
		std::strong_ordering operator<=>(const Rational& x) const;
		bool operator ==(const Rational& x) const;
#else
		bool operator >(Rational x);
		bool operator <(Rational x);
		bool operator >=(Rational x);
		bool operator <=(Rational x);
#endif
		Rational& operator+=(const Rational& a);
		Rational& operator-=(const Rational& a);
		Rational& operator*=(const Rational& a);
		Rational& operator/=(const Rational& a);
	};
	Rational operator + (const Rational& a, const Rational& b);
	Rational operator * (const Rational& a, const Rational& b);
	Rational operator - (const Rational& a, const Rational& b);
	Rational operator / (const Rational& a, const Rational& b);

	std::ostream& operator<< (std::ostream& stream, const Rational& rat);

	export int FindGreatestCommonDivisor(int a, int b);
	export int FindLeastCommonMultiple(int a, int b);
}

