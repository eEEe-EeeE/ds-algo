#include "Accumulator.h"



Accumulator::Accumulator(const Date & dat, const double & val) :
	lastDate(dat), value(val), sum(0)
{
}

Accumulator::~Accumulator()
{
}

double Accumulator::getSum(const Date & dat) const {
	return sum + value * dat.distance(lastDate);
}

void Accumulator::change(const Date & dat, const double & val) {
	sum = getSum(dat);
	value = val;
	lastDate = dat;
}

void Accumulator::reset(const Date & dat, const double & val) {
	sum = 0;
	value = val;
	lastDate = dat;
}
