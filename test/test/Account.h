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
	Account(const Date & dat, const std::string & id);
	~Account();
	//�ı��˻����ʹ�ӡ���仯
	void record(const Date & dat, const double & amount, const std::string & desc);
	//��ӡ������Ϣ
	void error(const std::string & msg) const;
public:
	std::string getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	virtual void show() const;
	virtual void deposit(const Date & dat, const double & amount, const std::string & desc) = 0;
	virtual void withdraw(const Date & dat, const double & amount, const std::string & desc) = 0;
	virtual void settle(const Date & dat) = 0;
};

