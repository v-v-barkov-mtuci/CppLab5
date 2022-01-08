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

Complex::Complex(double re, double im) {
	mod = hypot(re, im);
	mod = (mod < 0.000000000001) ? 0.0 : mod; // Ќе проходилс€ тест TestIfSubIsNotCommutative, т.к. при переходе к алгебраическому представлению вместо 0 получались малые числа
	arg = (mod == 0.0) ? 0.0 : atan2(im, re); // ≈сли модуль нулевой, аргумент не важен. —делано, чтобы проходилс€ вышеупом€нутый тест
};

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

Complex& Complex::operator++() {
	const double old_real = Re();
	const double new_real = old_real + 1.0;
	const double old_imag = Im();

	mod = hypot(new_real, old_imag);
	arg = atan2(old_imag, new_real);

	return *this;
};

Complex Complex::operator++(int) {
	Complex old = *this;
	
	const double old_real = Re();
	const double new_real = old_real + 1.0;
	const double old_imag = Im();

	mod = hypot(new_real, old_imag);
	arg = atan2(old_imag, new_real);

	return old;
};

Complex& Complex::operator--() {
	const double old_real = Re();
	const double new_real = old_real - 1.0;
	const double old_imag = Im();

	mod = hypot(new_real, old_imag);
	arg = atan2(old_imag, new_real);

	return *this;
};

Complex Complex::operator--(int) {
	Complex old = *this;

	const double old_real = Re();
	const double new_real = old_real - 1.0;
	const double old_imag = Im();

	mod = hypot(new_real, old_imag);
	arg = atan2(old_imag, new_real);

	return old;
};

Complex& Complex::operator+=(const Complex& a) {
	const double this_real = Re();
	const double this_imag = Im();

	const double a_real = a.Re();
	const double a_imag = a.Im();

	const double new_real = this_real + a_real;
	const double new_imag = this_imag + a_imag;

	mod = hypot(new_real, new_imag);
	arg = atan2(new_imag, new_real);

	return *this;
};

Complex& Complex::operator-=(const Complex& a) {
	const double this_real = Re();
	const double this_imag = Im();

	const double a_real = a.Re();
	const double a_imag = a.Im();

	const double new_real = this_real - a_real;
	const double new_imag = this_imag - a_imag;

	mod = hypot(new_real, new_imag);
	arg = atan2(new_imag, new_real);

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

Complex Math::operator + (const Complex a, const Complex b) {
	const double a_real = a.Re();
	const double a_imag = a.Im();

	const double b_real = b.Re();
	const double b_imag = b.Im();

	const double new_real = a_real + b_real;
	const double new_imag = a_imag + b_imag;

	return Complex(new_real, new_imag);
};

Complex Math::operator - (const Complex a, const Complex b) {
	const double a_real = a.Re();
	const double a_imag = a.Im();

	const double b_real = b.Re();
	const double b_imag = b.Im();

	const double new_real = a_real - b_real;
	const double new_imag = a_imag - b_imag;

	return Complex(new_real, new_imag);
};

Complex Math::operator * (const Complex a, const Complex b) {
	return Math::Complex::FromExponentialForm(a.Mod() * b.Mod(), a.Arg() + b.Arg());
};

Complex Math::operator / (const Complex a, const Complex b) {
	return Math::Complex::FromExponentialForm(a.Mod() / b.Mod(), a.Arg() - b.Arg());
};

Complex Math::operator "" i(long double x) {
	return Complex(0, x);
};