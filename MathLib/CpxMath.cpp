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

Complex::Complex(double re, double im) : mod(sqrt(im * im + re * re)), arg(atan2(im, re)) {};

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

	mod = sqrt(new_real * new_real + new_imag * new_imag);
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
	Complex sum = (*this) + a;

	std::swap(sum, *this);

	return *this;
};

Complex& Complex::operator-=(const Complex& a) {
	Complex sum = (*this) - a;

	std::swap(sum, *this);

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
	const double a_real = a.Re();
	const double a_imag = a.Im();

	const double b_real = b.Re();
	const double b_imag = b.Im();

	const double new_real = a_real + b_real;
	const double new_imag = a_imag + b_imag;

	return Complex(new_real, new_imag);
};

Complex Math::operator - (const Complex& a, const Complex& b) {
	Complex b_copy = b;

	return a + (-b_copy);
};

Complex Math::operator * (const Complex& a, const Complex& b) {
	return Math::Complex::FromExponentialForm(a.Mod() * b.Mod(), a.Arg() + b.Arg());
};

Complex Math::operator / (const Complex& a, const Complex& b) {
	return Math::Complex::FromExponentialForm(a.Mod() / b.Mod(), a.Arg() - b.Arg());
};

Complex Math::operator "" i(long double x) {
	return Complex(0, x);
};

std::ostream& Math::operator <<(std::ostream& stream, const Complex& cpx) {
	stream << "[ " << "Re = " << cpx.Re() << ", Im = " << cpx.Im() << " ]";
	return stream;
}