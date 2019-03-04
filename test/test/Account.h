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
	Account() {};
	Account(const Date & dat, const std::string & id);
	//改变账户余额和打印余额变化
	void record(const Date & dat, const double & amount, const std::string & desc);
	void error(const std::string & msg) const;
public:
	~Account();
	std::string getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	void show() const;

};

