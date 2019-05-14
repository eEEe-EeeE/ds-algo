#include "Complex.h"

using namespace std;

Complex::Complex(const double & re, const double & im) :
	real(re), imag(im)
{
}

Complex::~Complex()
{
}

Complex Complex::operator + (const Complex & rth) const {
	return Complex(real + rth.real, imag + rth.imag);
}

Complex Complex::operator - (const Complex & rth) const {
	return Complex(real - rth.real, imag - rth.imag);
}

Complex Complex::operator + (const double & rth) const {
	return Complex(real + rth, imag);
}

Complex Complex::operator - (const double & rth) const {
	return Complex(real - rth, imag);
}

Complex operator + (const double & lth, const Complex & rth) {
	return Complex(lth + rth.real, rth.imag);
}

Complex operator - (const double & lth, const Complex & rth) {
	return Complex(lth - rth.real, -rth.imag);
}

ostream & operator << (ostream & out, const Complex & c) {
	out << c.real << "+j" << c.imag;
	return out;
}
