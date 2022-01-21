#include <windows.h>

module Math;
using namespace Math;
Rational::Rational() : nom(0), denom(1) {};

Rational::Rational(int n, int d) {
	const int gcd = Math::FindGreatestCommonDivisor(n, d);
	const int sign = ((n * d) > 0) ? 1 : -1;
	nom = abs(n / gcd) * sign;
	denom = abs(d / gcd);
};

Rational::Rational(int n) : nom(n), denom(1) {};

int Rational::Nominator() const {
	return nom;
};

int Rational::Denominator() const {
	return denom;
};

Rational Math::operator + (const Rational& a, const Rational& b) {
	Rational copy = a;

	copy += b;

	return copy;
};

Rational Math::operator - (const Rational& a, const Rational& b) {
	Rational copy = a;

	copy -= b;

	return copy;
};

Rational Math::operator * (const Rational& a, const Rational& b) {
	Rational copy = a;

	copy *= b;

	return copy;
}

Rational Math::operator / (const Rational& a, const Rational& b) {
	Rational copy = a;

	copy /= b;

	return copy;
};

Rational::operator double() const {
	return ((double)nom) / ((double)denom);
};

Rational Rational::operator-() {
	return Rational(-nom, denom);
};

Rational& Rational::operator++() {
	nom += denom;
	return *this;
};

Rational Rational::operator++(int) {
	Rational copy = *this;

	++(*this);

	return copy;
};

Rational& Rational::operator--() {
	nom -= denom;
	return *this;
};

Rational Rational::operator--(int) {
	Rational copy = *this;

	--(*this);

	return copy;
};

bool Rational::operator ==(Rational x) {
	return (this->Nominator() == x.Nominator()) && (this->Denominator() == x.Denominator());
};

bool Rational::operator !=(Rational x) {
	return !((*this) == x);
};

bool Rational::operator >(Rational x) {
	const int lcm = Math::FindLeastCommonMultiple(this->Denominator(), x.Denominator());
	const int a_nom = MulDiv(this->Nominator(), lcm, this->Denominator());
	const int b_nom = MulDiv(x.Nominator(), lcm, x.Denominator());

	return a_nom > b_nom;
};

bool Rational::operator <(Rational x) {
	const int lcm = Math::FindLeastCommonMultiple(this->Denominator(), x.Denominator());
	const int a_nom = MulDiv(this->Nominator(), lcm, this->Denominator());
	const int b_nom = MulDiv(x.Nominator(), lcm, x.Denominator());

	return a_nom < b_nom;
};

bool Rational::operator >=(Rational x) {
	return ((*this) == x) || ((*this) > x);
};

bool Rational::operator <=(Rational x) {
	return ((*this) == x) || ((*this) < x);
};

Rational& Rational::operator+=(const Rational& a) {
	const int new_denom = Math::FindLeastCommonMultiple(this->Denominator(), a.Denominator());
	const int new_nom = MulDiv(this->Nominator(), new_denom, this->Denominator()) + MulDiv(a.Nominator(), new_denom, a.Denominator());

	const int gcd = Math::FindGreatestCommonDivisor(new_nom, new_denom);
	const int sign = ((new_nom * new_denom) > 0) ? 1 : -1;
	nom = abs(new_nom / gcd) * sign;
	denom = abs(new_denom / gcd);

	return *this;
};

Rational& Rational::operator-=(const Rational& a) {
	const int new_denom = Math::FindLeastCommonMultiple(this->Denominator(), a.Denominator());
	const int new_nom = MulDiv(this->Nominator(), new_denom, this->Denominator()) - MulDiv(a.Nominator(), new_denom, a.Denominator());

	const int gcd = Math::FindGreatestCommonDivisor(new_nom, new_denom);
	const int sign = ((new_nom * new_denom) > 0) ? 1 : -1;
	nom = abs(new_nom / gcd) * sign;
	denom = abs(new_denom / gcd);

	return *this;
};

Rational& Rational::operator*=(const Rational& a) {
	const int new_nom = this->Nominator() * a.Nominator();
	const int new_denom = this->Denominator() * a.Denominator();
	const int gcd = Math::FindGreatestCommonDivisor(new_nom, new_denom);

	nom = new_nom / gcd;
	denom = new_denom / gcd;

	return *this;
};

Rational& Rational::operator/=(const Rational& a) {
	const int new_nom = this->Nominator() * a.Denominator();
	const int new_denom = this->Denominator() * a.Nominator();
	const int gcd = Math::FindGreatestCommonDivisor(new_nom, new_denom);

	nom = new_nom / gcd;
	denom = new_denom / gcd;

	return *this;
};

std::ostream& Math::operator<< (std::ostream& stream, const Rational& rat) {
	stream << "[ " << rat.Nominator() << " / " << rat.Denominator() << " ]";
	return stream;
};

int Math::FindGreatestCommonDivisor(int a, int b) {
	a = abs(a);
	b = abs(b);
	int next;
	do {
		next = a % b;
		a = b;
		b = next;
	} while (next != 0);
	return a;
};

int Math::FindLeastCommonMultiple(int a, int b) {
	return abs(a * b) / Math::FindGreatestCommonDivisor(a, b);
};