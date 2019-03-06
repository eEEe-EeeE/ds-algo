#pragma once
#include <iostream>
class Complex
{
private:
	double real;
	double imag;
public:
	Complex() :
		real(0), imag(0) {}
	Complex(const double & re, const double & im);
	~Complex();
	Complex operator + (const Complex & r) const;
	Complex operator - (const Complex & r) const;

};

