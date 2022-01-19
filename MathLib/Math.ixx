#include <cmath>
#include <iostream>

export module Math;

namespace Math {
    export class Complex {
    private:
        double m_re;
        double m_im;
    public:
        Complex() :m_re(0), m_im(0) {}
        Complex(double re, double im) :m_re(re), m_im(im) {}
        Complex(double re) :m_re(re), m_im(0) {}
        static Complex FromExponentialForm(double mod, double arg) {
            double re = mod * cos(arg);
            double im = mod * sin(arg);
            return Complex(re, im);
        }
        static Complex FromAlgebraicForm(double re, double im) {
            return Complex(re, im);
        }
        double Re() const {
            return m_re;
        }
        double Im() const {
            return m_im;
        }
        double Mod() const {
            return sqrt(m_re * m_re + m_im * m_im);
        }
        double Arg() const {
            return atan2(m_im, m_re);
        }
        explicit operator double() {
            return Re();
        }
        Complex operator-() {
            return Complex(-m_re, -m_im);
        }
        Complex& operator++() {
            m_re += 1;
            return *this;
        }
        Complex& operator++(int) {
            Complex temp = *this;
            ++* this;
            return temp;
        }
        Complex& operator--() {
            m_re -= 1;
            return *this;
        }
        Complex& operator--(int) {
            Complex temp = *this;
            --* this;
            return temp;
        }
        Complex& operator+=(const Complex& x) {
            Complex temp = *this;
            temp.m_re += x.m_re;
            temp.m_im += x.m_im;
            return *this;
        }
        Complex& operator-=(const Complex& x) {
            Complex temp = *this;
            temp.m_re -= x.m_re;
            temp.m_im -= x.m_im;
            return *this;
        }
        Complex& operator*=(const Complex& x) {
            Complex temp = *this;
            temp = temp * x;
            return *this;
        }
        Complex& operator/=(const Complex& x) {
            Complex temp = *this;
            temp = temp / x;
            return *this;
        }
        Complex friend operator+(const Complex& x, const Complex& y) {
            return Complex(x.m_re + y.m_re, x.m_im + y.m_im);
        }
        Complex friend operator+(const double& x, const Complex& y) {
            return Complex(x + y.m_re, y.m_im);
        }
        Complex friend operator+(const Complex& x, const double& y) {
            return Complex(x.m_re + y, x.m_im);
        }
        Complex friend operator-(const Complex& x, const Complex& y) {
            return Complex(x.Re() - y.Re(), x.Im() - y.Im());
        }
        Complex friend operator * (const Complex& x, const Complex& y) {
            //return Complex((x.Re() * y.Re()) - (x.Im() * y.Im()), (x.Re() * y.Im()) + (y.Im() * x.Im()));
            return Complex((x.m_re * y.m_re) - (x.m_im * y.m_im), (x.m_re * y.m_im) + (y.m_im * x.m_im));
        }
        Complex friend operator*(const double& x, const Complex& y) {
            return Complex(x * y.Re(), x * y.Im());
        }
        Complex friend operator*(const Complex& x, const double& y) {
            return Complex(x.m_re * y, x.m_im * y);
        }
        Complex friend operator/(const Complex& x, const Complex& y) {
            return Complex(((x.Re() * y.Re() + x.Im() * y.Im()) / ((y.Re() * y.Re()) + (y.Im() * y.Im()))), ((x.Im() * y.Re() - x.Re() * y.Im()) / ((y.Re() * y.Re()) + (y.Im() * y.Im()))));
        }
        friend Complex operator"" i(unsigned long long d);
        friend Complex operator"" i(long double d);
        friend std::ostream& operator<<(std::ostream& os, const Complex& x);
    };
    export Complex operator"" i(unsigned long long d) {
        double newIm = d;
        return Complex(0.0, newIm);
    }
    export Complex operator"" i(long double d) {
        double newIm = d;
        return Complex(0.0, newIm);
    }
    export Complex f(const Complex& z) {
        Complex temp = z;
        return Complex(2, 0) + temp * tan((double)temp);
    }
    export std::ostream& operator<<(std::ostream& os, Complex& x) {
        os << x.Re() << " + " << x.Im() << "i";
        return os;
    }
    export int FindGreatestCommonDivisor(int a, int b) {
        if (b == 0) return a;
        return FindGreatestCommonDivisor(b, a % b);
    }
    export int FindLeastCommonMultiple(int x, int y) {
        return abs(x * y) / FindGreatestCommonDivisor(x, y);
    }
    export class Rational
    {
    private:
        int m_nominator;
        int m_denominator;
    public:
        Rational() :m_nominator(0), m_denominator(1) {}
        Rational(int nominator, int denominator) :m_nominator(nominator), m_denominator(denominator) {}
        Rational(int nominator) :m_nominator(nominator), m_denominator(1) {}
        void normalize() {
            int divisor = FindGreatestCommonDivisor(m_nominator, m_denominator);
            m_nominator = m_nominator / divisor;
            m_denominator = m_denominator / divisor;
        }
        int Nominator() const {
            return m_nominator;
        }
        int Denominator() const {
            return m_denominator;
        }
        explicit operator double() const {
            double decimal = (double)(m_nominator) / (double)(m_denominator);
            //std::cout << decimal << std::endl;
            return decimal;
        }
        Rational operator-() {
            return Rational(-m_nominator, m_denominator);
        }
        Rational& operator++() {
            m_nominator += m_denominator;
            return *this;
        }
        Rational& operator++(int) {
            Rational temp = *this;
            ++* this;
            return temp;
        }
        Rational& operator--() {
            m_nominator -= m_denominator;
            return *this;
        }
        Rational& operator--(int) {
            Rational temp = *this;
            --* this;
            return temp;
        }
        Rational& operator+=(const Rational& x) {
            Rational temp = *this;
            temp.m_nominator = temp.m_nominator - x.m_nominator;
            temp.m_denominator = temp.m_nominator + x.m_denominator;
            return *this;
        }
        Rational& operator-=(const Rational& x) {
            Rational temp = *this;
            temp.m_nominator = temp.m_nominator - x.m_nominator;
            temp.m_denominator = temp.m_nominator - x.m_denominator;
            return *this;
        }
        Rational& operator*=(const Rational& x) {
            Rational temp = *this;
            temp = temp * x;
            return *this;
        }
        Rational& operator/=(const Rational& x) {
            Rational temp = *this;
            temp = temp / x;
            return *this;
        }
        Rational friend operator+(const Rational& x, const Rational& y) {
            int divisor = FindLeastCommonMultiple(x.Denominator(), y.Denominator());
            Rational temp = Rational(x.Nominator() * divisor / x.Denominator() + y.Nominator() * divisor / y.Denominator(), divisor);
            temp.normalize();
            return temp;
        }
        Rational friend operator+(const Rational& x, const int& y) {
            Rational temp = Rational(x.m_nominator + y*x.m_denominator, x.m_denominator);
            //Rational temp = Rational(x.Nominator() + y.Nominator(), x.Denominator() + y.Denominator());
            temp.normalize();
            return temp;
        }
        Rational friend operator+(const int& x, const Rational& y) {
            Rational temp = Rational(y.m_nominator + x*y.m_denominator, y.m_denominator);
            //Rational temp = Rational(x.Nominator() + y.Nominator(), x.Denominator() + y.Denominator());
            temp.normalize();
            return temp;
        }
        Rational friend operator-(const Rational& x, const Rational& y) {
            Rational temp = Rational(x.Nominator() - y.Nominator(), x.Denominator() - y.Denominator());
            temp.normalize();
            return temp;
        }
        Rational friend operator*(const Rational& x, const Rational& y) {
            Rational temp = Rational(x.Nominator() * y.Nominator(), x.Denominator() * y.Denominator());
            temp.normalize();
            return temp;
        }
        Rational friend operator*(const Rational& x, const double& y) {
            int tempY = (int)(y * 100);

            Rational doubleTemp = Rational(tempY, 100);

            Rational temp = Rational(x.Nominator() * doubleTemp.Nominator(), x.Denominator() * doubleTemp.Denominator());
            temp.normalize();
            return temp;
        }
        Rational friend operator/(const Rational& x, const Rational& y) {
            Rational temp = Rational(x.Nominator() * y.Denominator(), x.Denominator() * y.Nominator());
            temp.normalize();
            return temp;
        }
        bool friend operator==(const Rational& x, const Rational& y) {
            double tempX = (double)x;
            double tempY = (double)y;
            if (tempX == tempY) {
                return true;
            }
            return false;
        }
        bool friend operator>(const Rational& x, const Rational& y) {
            double tempX = (double)x;
            double tempY = (double)y;
            if (tempX > tempY) {
                return true;
            }
            return false;
        }
        bool friend operator>=(const Rational& x, const Rational& y) {
            double tempX = (double)x;
            double tempY = (double)y;
            if (tempX >= tempY) {
                return true;
            }
            return false;
        }
        bool friend operator<(const Rational& x, const Rational& y) {
            double tempX = (double)x;
            double tempY = (double)y;
            if (tempX < tempY) {
                return true;
            }
            return false;
        }
        bool friend operator<=(const Rational& x, const Rational& y) {
            double tempX = (double)x.m_nominator / x.m_denominator;
            double tempY = (double)y.m_nominator / y.m_denominator;
            if (tempX <= tempY) {
                return true;
            }
            return false;
        }
        friend std::ostream& operator<<(std::ostream& os, const Rational& x);        
    };
    export std::ostream& operator<<(std::ostream& os, const Rational& x) {
        os << x.Nominator() << "/" << x.Denominator();
        return os;
    }
    export Rational f(const Rational& z) {
        Rational temp = z;
        return Rational(2, 1) + temp * tan((double)(temp));
    }
    export double f(const double& z) {
        return 2.0 + z * tan(z);
    }
}
