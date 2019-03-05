#pragma once
#include "Date.h"
//������Ϣʱ��Ҫ�����ۼӽ�����ƴ�����������Ϣ
class Accumulator {
private:
	//���һ��value�仯�����ڣ�ÿ��value�䶯�ͻ�ı�
	Date lastDate;
	//���ڼ��㰴���ۼƵ�ֵ
	double value;
	//���һ�ν�Ϣ�����ۼƺͣ�ÿ��lastDate�䶯�ͻ����
	double sum;
public:
	Accumulator(const Date & dat, const double & val);
	~Accumulator();
	double getValue() const { return value; }
	double getSum(const Date & dat) const;
	void change(const Date & dat, const double & val);
	void reset(const Date & dat, const double & val);
};

