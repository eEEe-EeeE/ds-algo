#pragma once
#include <string>
#include "Date.h"
class Account {
private:
	std::string id;
	double balance;
	//个人所有账户的总余额
	static double total;
protected:
	Account(const Date & dat, const std::string & id);
	~Account();
	//改变账户余额和打印余额变化
	void record(const Date & dat, const double & amount, const std::string & desc);
	//打印错误信息
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

