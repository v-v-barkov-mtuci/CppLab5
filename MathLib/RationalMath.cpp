#include <windows.h>

module Math;
using namespace Math;

Rational::Rational()
	: nominator(0),
	denominator(1)
{ }

Rational::Rational(int n, int d)
{
	const int NOD = Math::FindGreatestCommonDivisor(n, d);
	const int sign = ((n * d) > 0) ? 1 : -1;
	nominator = abs(n / NOD) * sign;
	denominator = abs(d / NOD);
}

Rational::Rational(int n)
	: nominator(n),
	denominator(1)
{ }

int Rational::Nominator() const
{
	return nominator;
}

int Rational::Denominator() const
{
	return denominator;
}

Rational Math::operator + (const Rational& left, const Rational& right)
{
	const int NOK = Math::FindLeastCommonMultiple(left.Denominator(), right.Denominator());
	return Rational(MulDiv(left.Nominator(), NOK, left.Denominator()) + MulDiv(right.Nominator(), NOK, right.Denominator()), NOK);
}

Rational Math::operator * (const Rational& left, const Rational& right)
{
	return Rational(left.Nominator() * right.Nominator(), left.Denominator() * right.Denominator());
}

Rational::operator double() const
{
	return ((double)nominator) / ((double)denominator);
}

Rational Rational::operator-()
{
	return Rational(-nominator, denominator);
}

Rational& Rational::operator++()
{
	nominator += denominator;
	return *this;
}

Rational Rational::operator++(int)
{
	Rational temp = *this;
	nominator += denominator;
	return temp;
}

Rational& Rational::operator--()
{
	nominator -= denominator;
	return *this;
}

Rational Rational::operator--(int)
{
	Rational temp = *this;
	nominator -= denominator;
	return temp;
}

Rational Math::operator - (const Rational& left, const Rational& right)
{
	const int NOK = Math::FindLeastCommonMultiple(left.Denominator(), right.Denominator());
	return Rational(MulDiv(left.Nominator(), NOK, left.Denominator()) - MulDiv(right.Nominator(), NOK, right.Denominator()), NOK);
}

Rational Math::operator / (const Rational& left, const Rational& right)
{
	return Rational(left.Nominator() * right.Denominator(), left.Denominator() * right.Nominator());
}

bool Rational::operator ==(Rational x)
{
	return (this->Nominator() == x.Nominator()) && (this->Denominator() == x.Denominator());
}

bool Rational::operator !=(Rational x)
{
	return (this->Nominator() != x.Nominator()) || (this->Denominator() != x.Denominator());
}
#if 0
std::strong_ordering Rational::operator<=>(const Rational& x) const
{
	const int NOK = Math::FindLeastCommonMultiple(this->Denominator(), x.Denominator());
	const int a_nom = MulDiv(this->Nominator(), NOK, this->Denominator());
	const int b_nom = MulDiv(x.Nominator(), NOK, x.Denominator());

	return a_nom <=> b_nom;
}
bool Rational::operator ==(const Rational& x) const
{
	return (*this <=> x) == std::strong_ordering::equivalent;
}
#else
bool Rational::operator >(Rational x)
{
	const int NOK = Math::FindLeastCommonMultiple(this->Denominator(), x.Denominator());
	const int a_nom = MulDiv(this->Nominator(), NOK, this->Denominator());
	const int b_nom = MulDiv(x.Nominator(), NOK, x.Denominator());

	return a_nom > b_nom;
}

bool Rational::operator <(Rational x)
{
	const int NOK = Math::FindLeastCommonMultiple(this->Denominator(), x.Denominator());
	const int a_nom = MulDiv(this->Nominator(), NOK, this->Denominator());
	const int b_nom = MulDiv(x.Nominator(), NOK, x.Denominator());

	return a_nom < b_nom;
}

bool Rational::operator >=(Rational x)
{
	return ((*this) == x) || ((*this) > x);
}

bool Rational::operator <=(Rational x)
{
	return ((*this) == x) || ((*this) < x);
}
#endif
Rational& Rational::operator+=(const Rational& right)
{
	const int new_denom = Math::FindLeastCommonMultiple(this->Denominator(), right.Denominator());
	const int new_nom = MulDiv(this->Nominator(), new_denom, this->Denominator()) + MulDiv(right.Nominator(), new_denom, right.Denominator());

	const int NOD = Math::FindGreatestCommonDivisor(new_nom, new_denom);
	const int sign = ((new_nom * new_denom) > 0) ? 1 : -1;
	nominator = abs(new_nom / NOD) * sign;
	denominator = abs(new_denom / NOD);

	return *this;
}

Rational& Rational::operator-=(const Rational& right)
{
	const int new_denom = Math::FindLeastCommonMultiple(this->Denominator(), right.Denominator());
	const int new_nom = MulDiv(this->Nominator(), new_denom, this->Denominator()) - MulDiv(right.Nominator(), new_denom, right.Denominator());

	const int NOD = Math::FindGreatestCommonDivisor(new_nom, new_denom);
	const int sign = ((new_nom * new_denom) > 0) ? 1 : -1;
	nominator = abs(new_nom / NOD) * sign;
	denominator = abs(new_denom / NOD);

	return *this;
}

Rational& Rational::operator*=(const Rational& right)
{
	const int new_nom = this->Nominator() * right.Nominator();
	const int new_denom = this->Denominator() * right.Denominator();
	const int NOD = Math::FindGreatestCommonDivisor(new_nom, new_denom);

	nominator = new_nom / NOD;
	denominator = new_denom / NOD;

	return *this;
}

Rational& Rational::operator/=(const Rational& right)
{
	const int new_nom = this->Nominator() * right.Denominator();
	const int new_denom = this->Denominator() * right.Nominator();
	const int NOD = Math::FindGreatestCommonDivisor(new_nom, new_denom);

	nominator = new_nom / NOD;
	denominator = new_denom / NOD;

	return *this;
}

std::ostream& Math::operator<< (std::ostream& stream, const Rational& rat)
{
	stream << "[ " << rat.Nominator() << " / " << rat.Denominator() << " ]";
	return stream;
}

int Math::FindGreatestCommonDivisor(int a, int b)
{
	a = abs(a);
	b = abs(b);
	int next;
	do {
		next = a % b;
		a = b;
		b = next;
	} while (next != 0);
	return a;
}

int Math::FindLeastCommonMultiple(int a, int b)
{
	return abs(a * b) / Math::FindGreatestCommonDivisor(a, b);
}