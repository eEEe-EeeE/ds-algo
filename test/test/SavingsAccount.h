#pragma once
#include "Account.h"
#include "Accumulator.h"
#include "Date.h"
#include <string>

class SavingsAccount :
	public Account
{
private:
	double rate;
	Accumulator acc;
public:
	SavingsAccount();
	~SavingsAccount();
	double getRate() const { return rate; }
	void deposit(const Date & dat, const double	& amount, const std::string & desc);
	void withdraw(const Date & dat, const double & amount, const std::string & desc);
	void settle(const Date & dat);

};