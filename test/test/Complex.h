#pragma once
#include <iostream>
class Complex
{
private:
	double real;
	double imag;
	friend Complex operator + (const double & l, const Complex & r);
	friend Complex operator - (const double & l, const Complex & r);
	friend std::ostream & operator << (std::ostream & out, const Complex & c);
public:
	Complex() :
		real(0), imag(0) {}
	Complex(const double & re, const double & im);
	~Complex();
	Complex operator + (const Complex & r) const;
	Complex operator - (const Complex & r) const;
	Complex operator + (const double & r) const;
	Complex operator - (const double & r) const;
};

