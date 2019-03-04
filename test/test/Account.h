#pragma once
#include <string>
#include "Date.h"
class Account {
private:
	std::string id;
	double balance;
	static double total;
protected:
	Account() {};
	Account(Date dat, std::string id);
	void record(Date dat, double amount, std::string desc);
	void error(std::string msg) const;
public:
	std::string getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	void show() const;
	~Account();

};

