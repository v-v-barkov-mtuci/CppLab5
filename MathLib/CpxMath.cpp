module Math;

using namespace Math;

double Complex::Re() const {
	return real;
}

double Complex::Im() const {
	return imag;
}

double Complex::Mod() const {
	return mod;
}

double Complex::Arg() const {
	return arg;
}

Complex::Complex(double re, double im, double m, double a) : real(re), imag(im), mod(m), arg(a) {};

Complex::Complex() : real(0), imag(0), mod(0), arg(0) {};

Complex::Complex(double i) : real(i), mod(i), imag(0), arg(0) {};

Complex::Complex(double a, double b) : real(a), imag(b) {
	mod = hypot(a, b);
	if ((a == +0.0) || (a == -0.0)) {
		arg = 0.0;
	} else {
		arg = atan(b / a);
	}
};

Complex Complex::FromAlgebraicForm(double re, double im) {
	return Complex(re, im, hypot(re, im), atan(im / re));
};

Complex Complex::FromExponentialForm(double m, double a) {
	return Complex(m * cos(a), m * sin(a), m, a);
};

Complex::operator double() const {
	return real;
};

Complex Complex::operator-() {
	return Complex(-real, -imag, mod, arg-3.14159265358979323846);
};

Complex& Complex::operator++() {
	real++;
	UpdateExp();
	return *this;
};

Complex Complex::operator++(int) {
	Complex old = *this;
	real++;
	UpdateExp();
	return old;
};

Complex& Complex::operator--() {
	real--;
	UpdateExp();
	return *this;
};

Complex Complex::operator--(int) {
	Complex old = *this;
	real--;
	UpdateExp();
	return old;
};

Complex& Complex::operator+=(const Complex& a) {
	real += a.Re();
	imag += a.Im();
	UpdateExp();
	return *this;
};

Complex& Complex::operator-=(const Complex& a) {
	real -= a.Re();
	imag -= a.Im();
	UpdateExp();
	return *this;
};

Complex& Complex::operator*=(const Complex& a) {
	double tmp_real = Re() * a.Re() - Im() * a.Im();
	double tmp_imag = Re() * a.Im() + Im() * a.Re();
	mod = Mod() * a.Mod();
	arg = Arg() + a.Arg();
	
	real = tmp_real;
	imag = tmp_imag;

	return *this;
};

Complex& Complex::operator/=(const Complex& a) {
	const double denom = (a.Re() * a.Re() + a.Im() * a.Im());
	double tmp_real = (real * a.Re() + imag * a.Im()) / denom;
	double tmp_imag = (imag * a.Re() - real * a.Im()) / denom;
	mod = Mod() / a.Mod();
	arg = Arg() - a.Arg();

	real = tmp_real;
	imag = tmp_imag;

	return *this;
};

void Complex::UpdateExp() {
	mod = hypot(real, imag);
	arg = atan(imag / real);
};

void Complex::UpdateAlg() {
	real = mod * cos(arg);
	imag = mod * sin(arg);
};

Complex Math::operator + (const Complex a, const Complex b) {
	return Complex(a.Re() + b.Re(), a.Im() + b.Im());
};

Complex Math::operator - (const Complex a, const Complex b) {
	return Complex(a.Re() - b.Re(), a.Im() - b.Im());
};

Complex Math::operator * (const Complex a, const Complex b) {
	const double tmp_real = a.Re() * b.Re() - a.Im() * b.Im();
	const double tmp_imag = a.Re() * b.Im() + a.Im() * b.Re();

	return Complex(tmp_real, tmp_imag);
};

Complex Math::operator / (const Complex a, const Complex b) {
	const double denom = b.Re() * b.Re() + b.Im() * b.Im();
	const double tmp_real = (a.Re() * b.Re() + a.Im() * b.Im()) / denom;
	const double tmp_imag = (a.Im() * b.Re() - a.Re() * b.Im()) / denom;

	return Complex(tmp_real, tmp_imag);
};

Complex Math::operator "" i(long double x) {
	return Complex(0, (double) x);
};