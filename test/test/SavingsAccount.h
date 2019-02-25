#ifndef _SAVINGSACCOUNT_H
#define _SAVINGSACCOUNT_H
#include <cmath>
#include <iostream>
#include <string>
#include "Date.h"

class SavingsAccount {
private:
	std::string id;
	double balance;
	double rate;
	Date lastDate;
	double accumulation;
	static double total;

	void record(const Date & date, double amount, const std::string & desc);
	double accumulate(const Date & date);
	void error(const std::string & err) const;
public:
	SavingsAccount(Date date, std::string id, double rate)
		:id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
		std::cout << "id: " << id << " The account is created." << std::endl;
	}
	const std::string & getId() const { return id; }
	const double & getBalance() const { return balance; }
	const double & getRate() const { return rate; }
	const static double & getTotal() { return total; }
	void show() const;
	void deposit(const Date & date, double amount, const std::string & desc);
	void withdraw(const Date & date, double amount, const std::string & desc);
	void settle(const Date & date);
};
#endif