export module Math;
import <cmath>;
import <string_view>;
import <iostream>;

export namespace Math {
	export extern const double abs_threshold;

	class Complex {
	private:
		double re;
		double im;

		void DeltaRealPart(const double delta);

	public:
		double Re() const;
		double Im() const;
		double Mod() const;
		double Arg() const;

		Complex();
		Complex(double i);
		Complex(double re, double im);

		static Complex FromAlgebraicForm(double re, double im);
		static Complex FromExponentialForm(double m, double a);

		explicit operator double() const;

		Complex operator-();

		Complex& operator++();
		Complex operator++(int);

		Complex& operator--();
		Complex operator--(int);

		Complex& operator+=(const Complex& a);
		Complex& operator-=(const Complex& a);
		Complex& operator*=(const Complex& a);
		Complex& operator/=(const Complex& a);
	};

	Complex operator + (const Complex& a, const Complex& b);
	Complex operator - (const Complex& a, const Complex& b);
	Complex operator * (const Complex& a, const Complex& b);
	Complex operator / (const Complex& a, const Complex& b);

	Complex operator "" i(long double x);

	std::ostream& operator<< (std::ostream& stream, const Complex& cpx);

	class Rational {
	private:
		int nom, denom;
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

		bool operator >(Rational x);
		bool operator <(Rational x);

		bool operator >=(Rational x);
		bool operator <=(Rational x);

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