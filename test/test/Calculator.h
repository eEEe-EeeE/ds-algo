#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Stack.h"

class Calculator {
private:
	Stack<double> stack;
	void enter(const double & num);
	bool getTwoOperands(double & opnd1, double & opnd2);
	void compute(const char & op);
	void error(const std::string & msg) const {
		std::cout << msg << std::endl;
	}
public:
	void run();
	void clear();
};