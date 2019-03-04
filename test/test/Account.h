#pragma once
#include <string>
#include "Date.h"
class Account {
private:
	std::string id;
	double balance;
	//���������˻��������
	static double total;
protected:
	Account() {};
	Account(const Date & dat, const std::string & id);
	//�ı��˻����ʹ�ӡ���仯
	void record(const Date & dat, const double & amount, const std::string & desc);
	void error(const std::string & msg) const;
public:
	~Account();
	std::string getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	void show() const;

};

