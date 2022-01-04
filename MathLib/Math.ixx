export module Math;
import <cmath>;

export namespace Math {
	class Complex {
	private:
		double real;
		double imag;
		double mod;
		double arg;

		Complex(double re, double im, double m, double a);

		void UpdateExp();
		void UpdateAlg();
	public:
		double Re() const;
		double Im() const;
		double Mod() const;
		double Arg() const;

		Complex();
		Complex(double i);
		Complex(double a, double b);

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

	Complex operator + (const Complex a, const Complex b);
	Complex operator - (const Complex a, const Complex b);
	Complex operator * (const Complex a, const Complex b);
	Complex operator / (const Complex a, const Complex b);
	
	Complex operator "" i(long double x);

	class Rational {
	private:
		int nom, denom;
	public:
		Rational();
		Rational(int n, int d);
		Rational(int n);

		int Nominator() const;
		int Denominator() const;

		static int GCD(int a, int b);
		static int LCM(int a, int b);
		static int ABS(int a);

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

	Rational operator + (const Rational a, const Rational b);
	Rational operator * (const Rational a, const Rational b);
	Rational operator - (const Rational a, const Rational b);
	Rational operator / (const Rational a, const Rational b);

	export int FindGreatestCommonDivisor(int a, int b);
	export int FindLeastCommonMultiple(int a, int b);
}