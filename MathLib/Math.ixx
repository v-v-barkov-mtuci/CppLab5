module;
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
export module Math;
export namespace Math {
	class Complex {
	public:
		Complex(double m_re = 0, double m_im = 0): m_mod(hypot(m_re, m_im)), m_arg(atan2(m_im, m_re)) 
		{
			Normalize();
		}
		void Normalize() {
			if (abs(m_mod) < 1E-10)
				m_mod = 0;
			if (abs(m_arg - M_PI) < 1E-10)
				m_arg = 0;
		}

		static Complex FromExponentialForm(double mod, double arg)
		{
			return Complex(mod * cos(arg), mod * sin(arg));
		}
		static Complex FromAlgebraicForm(double re, double im)
		{
			return Complex(re, im);
		}



		double Re() const { return (m_mod * cos(m_arg)); }
		double Im() const { return (m_mod * sin(m_arg)); }
		double Mod() const { return m_mod; }
		double Arg() const { return m_arg; }
		double pl() const { return Re() + 1;}
		double min() const { return Re() - 1;}

		explicit operator double() const { return m_mod * cos(m_arg); }
		Complex operator -() const { return Complex(-Re(), -Im()); }

		Complex& operator ++() {
			double t_mod = hypot(pl(), Im());
			double t_arg = atan2(Im(), pl());
			m_mod = t_mod;
			m_arg = t_arg;
			return *this;
		}
		Complex operator ++(int) {
			Complex c(Re(), Im());
			++(*this);
			return c;
		}
		Complex& operator --() {
			double t_mod = hypot(min(), Im());
			double t_arg = atan2(Im(), min());
			m_mod = t_mod;
			m_arg = t_arg;
			return *this;
		}
		Complex operator --(int) {
			Complex c(Re(), Im());
			--(*this);
			return c;
		}

		friend Complex operator +(const Complex& lhs, const Complex& rhs);
		friend Complex operator -(const Complex& lhs, const Complex& rhs);
		friend Complex operator *(const Complex& lhs, const Complex& rhs);
		friend Complex operator /(const Complex& lhs, const Complex& rhs);
		friend Complex operator ""i(long double im);
		friend Complex operator ""i(unsigned long long im);
		friend std::ostream& operator<< (std::ostream& stream, const Complex& instance);

		Complex& operator +=(const Complex& rhs) {
			Complex c = Complex(Re() + rhs.Re(), Im() + rhs.Im());
			m_mod = c.m_mod;
			m_arg = c.m_arg;
			Normalize();
			return *this;
		}
		Complex& operator -=(const Complex& rhs) {
			Complex c = Complex(Re() - rhs.Re(), Im() - rhs.Im());
			m_mod = c.m_mod;
			m_arg = c.m_arg;
			Normalize();
			return *this;
		}
		Complex& operator *=(const Complex& rhs) {
			m_mod *= rhs.m_mod ;
			m_arg += rhs.m_arg;
			Normalize();
			return *this;
		}
		Complex& operator /=(const Complex& rhs) {
			m_mod /= rhs.m_mod;
			m_arg -= rhs.m_arg;
			Normalize();
			return *this;
		}

	private:
		double m_mod;
		double m_arg;
	};

	Complex operator +(const Complex& lhs, const Complex& rhs) {
		Complex z = lhs;
		z += rhs;
		return z;
	}
	Complex operator -(const Complex& lhs, const Complex& rhs)
	{
		Complex z = lhs;
		z -= rhs;
		return z;
	}

	Complex operator *(const Complex& lhs, const Complex& rhs) {
		Complex z = lhs;
		z *= rhs;
		return z;
	}
	Complex operator /(const Complex& lhs, const Complex& rhs) {
		Complex z = lhs;
		z /= rhs;
		return z;
	}

	Complex operator ""i(long double im) {
		return Complex::FromAlgebraicForm(0, im);
	}
	Complex operator ""i(unsigned long long im) {
		return Complex::FromAlgebraicForm(0, im);
	}
	std::ostream& operator<< (std::ostream& stream, const Complex& complex) {
		stream << complex.Re() << " + " << complex.Im() << "i";
		return stream;
	}

	unsigned int FindGreatestCommonDivisor(int a1, int b1) {
		unsigned int a = abs(a1), b = abs(b1);
		if (a % b == 0)
			return b;
		if (b % a == 0)
			return a;
		if (a > b)
			return FindGreatestCommonDivisor(a % b, b);
		return FindGreatestCommonDivisor(a, b % a);
	}

	unsigned int FindLeastCommonMultiple(int a1, int b1) {
		unsigned int a = abs(a1), b = abs(b1);
		return (a * b) / FindGreatestCommonDivisor(a, b);
	}

	class Rational {
	public:
		void Normalize() {
			int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
			m_nominator /= nod;
			m_denominator /= nod;
			if (m_denominator < 0) {
				m_nominator = -m_nominator;
				m_denominator = -m_denominator;
			}
		}

		Rational() : Rational(0, 1) { }
		Rational(int n) : Rational(n, 1) { }
		Rational(int n, int d) : m_nominator(n), m_denominator(d) { Normalize(); }
		~Rational() { }
		int Nominator() const { return m_nominator; }
		int Denominator() const { return m_denominator; }



		explicit operator double() const { return ((double)m_nominator) / m_denominator; }
		Rational operator -() { return Rational(-m_nominator, m_denominator); }
		Rational& operator ++() {
			m_nominator += m_denominator;
			Normalize();
			return *this;
		}
		Rational operator ++(int) {
			Rational r(m_nominator, m_denominator);
			++(*this);
			return r;
		}
		Rational& operator --() {
			m_nominator -= m_denominator;
			Normalize();
			return *this;
		}
		Rational operator --(int) {
			Rational r(m_nominator, m_denominator);
			--(*this);
			return r;
		}

		Rational& operator +=(const Rational& rhs) {
			int nok = FindLeastCommonMultiple(m_denominator, rhs.m_denominator);
			int multL = nok / m_denominator, multR = nok / rhs.m_denominator;
			m_nominator = m_nominator * multL + rhs.m_nominator * multR;
			m_denominator = nok;
			Normalize();
			return *this;
		}
		Rational& operator -=(const Rational& rhs) {
			int nok = FindLeastCommonMultiple(m_denominator, rhs.m_denominator);
			int multL = nok / m_denominator, multR = nok / rhs.m_denominator;
			m_nominator = m_nominator * multL - rhs.m_nominator * multR;
			m_denominator = nok;
			Normalize();
			return *this;
		}
		Rational& operator *=(const Rational& rhs) {
			m_nominator *= rhs.m_nominator;
			m_denominator *= rhs.m_denominator;
			Normalize();
			return *this;
		}
		Rational& operator /=(const Rational& rhs) {
			m_nominator *= rhs.m_denominator;
			m_denominator *= rhs.m_nominator;
			Normalize();
			return *this;
		}

		friend Rational operator +(const Rational& lhs, const Rational& rhs);
		friend Rational operator -(const Rational& lhs, const Rational& rhs);
		friend Rational operator *(const Rational& lhs, const Rational& rhs);
		friend Rational operator /(const Rational& lhs, const Rational& rhs);
		friend bool operator ==(const Rational& lhs, const Rational& rhs);
		friend bool operator <(const Rational& lhs, const Rational& rhs);
		friend bool operator <=(const Rational& lhs, const Rational& rhs);
		friend bool operator >(const Rational& lhs, const Rational& rhs);
		friend bool operator >=(const Rational& lhs, const Rational& rhs);
		friend std::ostream& operator <<(std::ostream& stream, const Rational& instance);


	private:
		int m_nominator, m_denominator;
	};
	Rational operator +(const Rational& lhs, const Rational& rhs)
	{
		int nok = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
		int multL = nok / lhs.m_denominator, multR = nok / rhs.m_denominator;
		return Rational(lhs.m_nominator * multL + rhs.m_nominator * multR, nok);
	}
	Rational operator -(const Rational& lhs, const Rational& rhs)
	{
		int nok = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
		int multL = nok / lhs.m_denominator, multR = nok / rhs.m_denominator;
		return Rational(lhs.m_nominator * multL - rhs.m_nominator * multR, nok);
	}
	Rational operator *(const Rational& lhs, const Rational& rhs) {
		return Rational(lhs.m_nominator * rhs.m_nominator, lhs.m_denominator * rhs.m_denominator);
	}
	Rational operator /(const Rational& lhs, const Rational& rhs) {
		return Rational(lhs.m_nominator * rhs.m_denominator, lhs.m_denominator * rhs.m_nominator);
	}
	bool operator ==(const Rational& lhs, const Rational& rhs) {
		return lhs.m_nominator == rhs.m_nominator && lhs.m_denominator == rhs.m_denominator;
	}
	bool operator < (const Rational& lhs, const Rational& rhs) {
		return ((rhs - lhs).m_nominator > 0);
	}
	bool operator <= (const Rational& lhs, const Rational& rhs) {
		return ((rhs - lhs).m_nominator >= 0);
	}
	bool operator > (const Rational& lhs, const Rational& rhs) {
		return ((rhs - lhs).m_nominator < 0);
	}
	bool operator >= (const Rational& lhs, const Rational& rhs) {
		return ((rhs - lhs).m_nominator <= 0);
	}
	std::ostream& operator <<(std::ostream& stream, const Rational& instance) {
		stream << instance.m_nominator << " / " << instance.m_denominator;
		return stream;
	}
}
// Var 21

