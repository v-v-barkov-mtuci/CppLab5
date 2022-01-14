module Math;
using namespace Math;

double Complex::Re() const {
	return mod*cos(arg);
}

double Complex::Im() const {
	return mod*sin(arg);
}

double Complex::Mod() const {
	return mod;
}

double Complex::Arg() const {
	return arg;
}

Complex::Complex(double re, double im) : mod((hypot(re, im) < 0.000000000001) ? 0.0 : hypot(re, im)), arg((sqrt(im* im + re * re) < 0.000000000001) ? 0.0 : atan2(im, re)) {};

Complex::Complex() : mod(0), arg(0) {};

Complex::Complex(double i) : mod(i), arg(0) {};

Complex Complex::FromAlgebraicForm(double re, double im) {
	return Complex(re, im);
};

Complex Complex::FromExponentialForm(double m, double a) {
	return Complex(m*cos(a), m*sin(a));
};

Complex::operator double() const {
	return this->Re();
};

Complex Complex::operator-() {
	return Complex(-Re(), -Im());
};

void Complex::DeltaRealPart(const double delta) {
	const double new_real = Re() + delta;
	const double new_imag = Im();

	mod = hypot(new_real, new_imag);
	arg = atan2(new_imag, new_real);
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
	mod = Mod() * a.Mod();
	arg = Arg() + a.Arg();

	return *this;
};

Complex& Complex::operator/=(const Complex& a) {
	mod = Mod() / a.Mod();
	arg = Arg() - a.Arg();

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
	stream << "[ " << "Re = " << cpx.Re() << ", Im = " << cpx.Im() << " ]";
	return stream;
}