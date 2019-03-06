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

