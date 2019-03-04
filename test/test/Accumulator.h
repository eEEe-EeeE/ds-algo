#pragma once
#include "Date.h"
class Accumulator {
private:
	Date lastDate;
	double value;
	double sum;
public:
	Accumulator();
	~Accumulator();
	double getSum(Date dat);
	void change(Date dat, double v);
	void reset(Date dat, double v);
};

