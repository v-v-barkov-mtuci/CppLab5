module Math;
using namespace Math;

double Complex::Re() const {
	return re;
};

double Complex::Im() const {
	return im;
};

double Complex::Mod() const {
	return hypot(re, im);
};

double Complex::Arg() const {
	return atan2(im, re);
};

Complex::Complex() : re(0), im(0) {};

Complex::Complex(double re, double im) : re(re), im(im) {};

Complex::Complex(double i) : re(i), im(0) {};

Complex Complex::FromAlgebraicForm(double re, double im) {
	return Complex(re, im);
};

Complex Complex::FromExponentialForm(double m, double a) {
	return Complex(m * cos(a), m * sin(a));
};

Complex::operator double() const {
	return this->Re();
};

Complex Complex::operator-() {
	return Complex(-Re(), -Im());
};

void Complex::DeltaRealPart(const double delta) {
	re = Re() + delta;
	im = Im();
};

Complex& Complex::operator++() {
	Complex::DeltaRealPart(1.0);

	return *this;
};

Complex Complex::operator++(int) {
	Complex old = *this;

	++(*this);

	return old;
};

Complex& Complex::operator--() {
	Complex::DeltaRealPart(-1.0);

	return *this;
};

Complex Complex::operator--(int) {
	Complex old = *this;

	--(*this);

	return old;
};

Complex& Complex::operator+=(const Complex& a) {
	Complex sum = Complex(this->Re() + a.Re(), this->Im() + a.Im());

	std::swap(sum, *this);

	return *this;
};

Complex& Complex::operator-=(const Complex& a) {
	Complex delta = Complex(this->Re() - a.Re(), this->Im() - a.Im());

	std::swap(delta, *this);

	return *this;
};

Complex& Complex::operator*=(const Complex& a) {
	
	double keepreal = re;
	re = Re() * a.Re() - Im() * a.Im();
	im = keepreal * a.Im() + im * a.Re();

	return *this;
};

Complex& Complex::operator/=(const Complex& a) {
	double realkeep = Re();
	re = (Re() * a.Re() + Im() * a.Im()) / (a.Re() * a.Re() + a.Im() * a.Im());
	im = (Im() * a.Re() - realkeep * a.Im()) / (a.Re() * a.Re() + a.Im() * a.Im());
	return *this;
};

Complex Math::operator + (const Complex& a, const Complex& b) {
	Complex copy = a;

	copy += b;

	return copy;
};

Complex Math::operator - (const Complex& a, const Complex& b) {
	Complex copy = a;

	copy -= b;

	return copy;
};

Complex Math::operator * (const Complex& a, const Complex& b) {
	Complex copy = a;

	copy *= b;

	return copy;
};

Complex Math::operator / (const Complex& a, const Complex& b) {
	Complex copy = a;

	copy /= b;

	return copy;
};

Complex Math::operator "" i(long double x) {
	return Complex(0, x);
};

std::ostream& Math::operator <<(std::ostream& stream, const Complex& cpx) {
	stream << "[Re = " << cpx.Re() << ", Im = " << cpx.Im() << "]";
	return stream;
}