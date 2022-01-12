module Math;
using namespace Math;

Complex::Complex()
	: r(0),
	phi(0)
{ }

Complex::Complex(double a)
	: r(a),
	phi(0)
{ }

Complex::Complex(double re, double im)
	: r(sqrt(im* im + re * re)),
	phi(atan2(im, re))
{ }

Complex Complex::FromAlgebraicForm(double re, double im)
{
	return Complex(re, im);
}

Complex Complex::FromExponentialForm(double m, double a)
{
	return Complex(m * cos(a), m * sin(a));
}

double Complex::Re() const
{
	return r * cos(phi);
}

double Complex::Im() const
{
	return r * sin(phi);
}

double Complex::Mod() const
{
	return r;
}

double Complex::Arg() const
{
	return phi;
}

Complex::operator double() const
{
	return this->Re();
}

Complex Complex::operator-()
{
	return Complex(-Re(), -Im());
}

void Complex::DeltaRe(const double delta)
{
	const double new_re = Re() + delta;
	const double new_im = Im();
	r = sqrt(new_re * new_re + new_im * new_im);
	phi = atan2(new_im, new_re);
}

Complex& Complex::operator++()
{
	Complex::DeltaRe(1.0);
	return *this;
}

Complex Complex::operator++(int)
{
	Complex temp = *this;
	++(*this);
	return temp;
}

Complex& Complex::operator--()
{
	Complex::DeltaRe(-1.0);
	return *this;
}

Complex Complex::operator--(int)
{
	Complex temp = *this;
	--(*this);
	return temp;
}

Complex& Complex::operator+=(const Complex& left)
{
	Complex sum = (*this) + left;
	std::swap(sum, *this);
	return *this;
}

Complex& Complex::operator-=(const Complex& left)
{
	Complex sum = (*this) - left;
	std::swap(sum, *this);
	return *this;
}

Complex& Complex::operator*=(const Complex& left)
{
	r = Mod() * left.Mod();
	phi = Arg() + left.Arg();
	return *this;
}

Complex& Complex::operator/=(const Complex& left)
{
	r = Mod() / left.Mod();
	phi = Arg() - left.Arg();
	return *this;
}

Complex Math::operator + (const Complex& left, const Complex& right)
{
	const double left_re = left.Re();
	const double left_im = left.Im();
	const double right_re = right.Re();
	const double right_im = right.Im();
	const double new_re = left_re + right_re;
	const double new_im = left_im + right_im;

	return Complex(new_re, new_im);
}

Complex Math::operator - (const Complex& left, const Complex& right)
{
	Complex right_c = right;
	return left + (-right_c);
}

Complex Math::operator * (const Complex& left, const Complex& right)
{
	return Math::Complex::FromExponentialForm(left.Mod() * right.Mod(), left.Arg() + right.Arg());
}

Complex Math::operator / (const Complex& left, const Complex& right)
{
	return Math::Complex::FromExponentialForm(left.Mod() / right.Mod(), left.Arg() - right.Arg());
}

Complex Math::operator "" i(long double x)
{
	return Complex(0, x);
}

std::ostream& Math::operator <<(std::ostream& stream, const Complex& complex)
{
	stream << "[ " << "Re = " << complex.Re() << ", Im = " << complex.Im() << " ]";
	return stream;
}