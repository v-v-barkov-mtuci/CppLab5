#include <math.h>
#include <iostream>
export module Math;

export namespace Math {
	class Complex {
	public:
		Complex(double re = 0, double im = 0) : m_re(re), m_im(im) { }

		static Complex FromExponentialForm(double abs, double ph)
		{
			return Complex(abs * cos(ph), abs * sin(ph));
		}
		static Complex FromAlgebraicForm(double re, double im)
		{
			return Complex(re, im);
		}


		double Re() const { return m_re; }
		double Im() const { return m_im; }
		double Mod() const { return sqrt(m_re * m_re + m_im * m_im); }
		double Arg() const { return atan2(m_im, m_re); }

		explicit operator double() const { return m_re; }
		Complex operator -() const { return Complex(-m_re, -m_im); }

		Complex& operator ++() { ++m_re; return *this; }
		Complex operator ++(int) {
			Complex c(m_re, m_im);
			++(*this);
			return c;
		}
		Complex& operator --() { --m_re; return *this; }
		Complex operator --(int) {
			Complex c(m_re, m_im);
			--(*this);
			return c;
		}


		friend std::ostream& operator<< (std::ostream& stream, const Complex& instance);

		Complex& operator +=(const Complex& rhs) {
			m_re += rhs.m_re;
			m_im += rhs.m_im;
			return *this;
		}
		Complex& operator -=(const Complex& rhs) {
			m_re -= rhs.m_re;
			m_im -= rhs.m_im;
			return *this;
		}
		Complex& operator *=(const Complex& rhs) {
			double t_re, t_im;
			t_re = m_re * rhs.m_re - m_im * rhs.m_im;
			t_im = m_re * rhs.m_im + m_im * rhs.m_re;
			m_re = t_re;
			m_im = t_im;
			return *this;
		}
		Complex& operator /=(const Complex& rhs) {
			double t_re, t_im;
			t_re = (m_re * rhs.m_re + m_im * rhs.m_im) / (rhs.m_re * rhs.m_re + rhs.m_im * rhs.m_im);
			t_im = (-m_re * rhs.m_im + m_im * rhs.m_re) / (rhs.m_re * rhs.m_re + rhs.m_im * rhs.m_im);
			m_re = t_re;
			m_im = t_im;
			return *this;
		}

	private:
		double m_re, m_im;
	};
	Complex operator +(const Complex& lhs, const Complex& rhs) {
		Complex c = lhs;
		c += rhs;
		return c;
	}
	Complex operator -(const Complex& lhs, const Complex& rhs)
	{
		Complex c = lhs;
		c -= rhs;
		return c;
	}
	Complex operator *(const Complex& lhs, const Complex& rhs) {
		Complex c = lhs;
		c *= rhs;
		return c;
	}
	Complex operator /(const Complex& lhs, const Complex& rhs) {
		Complex c = lhs;
		c /= rhs;
		return c;
	}

	Complex operator ""i(long double im) {
		return Complex(0, im);
	}
	Complex operator ""i(unsigned long long im) {
		return Complex(0, im);
	}
	std::ostream& operator<< (std::ostream& stream, const Complex& complex) {
		stream << complex.m_re << " + " << complex.m_im << "i";
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

		Rational(int n = 0, int d = 1) : m_nominator(n), m_denominator(d) { Normalize(); }
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
		friend bool operator ==(const Rational& lhs, const Rational& rhs);
		friend bool operator <(const Rational& lhs, const Rational& rhs);
		friend bool operator <=(const Rational& lhs, const Rational& rhs);
		friend bool operator >(const Rational& lhs, const Rational& rhs);
		friend bool operator >=(const Rational& lhs, const Rational& rhs);
		friend std::ostream& operator <<(std::ostream& stream, const Rational& instance);


	private:
		int m_nominator, m_denominator;
		void Normalize() {
			int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
			m_nominator /= nod;
			m_denominator /= nod;
			if (m_denominator < 0) {
				m_nominator = -m_nominator;
				m_denominator = -m_denominator;
			}
		}
	};
	Rational operator +(const Rational& lhs, const Rational& rhs)
	{
		Rational r = lhs;
		r += rhs;
		return r;
	}
	Rational operator -(const Rational& lhs, const Rational& rhs)
	{
		Rational r = lhs;
		r -= rhs;
		return r;
	}
	Rational operator *(const Rational& lhs, const Rational& rhs) {
		Rational r = lhs;
		r *= rhs;
		return r;
	}
	Rational operator /(const Rational& lhs, const Rational& rhs) {
		Rational r = lhs;
		r /= rhs;
		return r;
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


