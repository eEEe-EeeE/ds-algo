#pragma once
#include "Date.h"
//计算利息时需要按日累加金额，故设计此类来计算利息
class Accumulator {
private:
	//最近一次value变化的日期，每次value变动就会改变
	Date lastDate;
	//用于计算按日累计的值
	double value;
	//最近一次结息按日累计和，每次lastDate变动就会计算
	double sum;
public:
	Accumulator(const Date & dat, const double & val);
	~Accumulator();
	double getValue() const { return value; }
	double getSum(const Date & dat) const;
	void change(const Date & dat, const double & val);
	void reset(const Date & dat, const double & val);
};

