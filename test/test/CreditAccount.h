#pragma once
#include "Account.h"
#include "Accumulator.h"
#include "Date.h"
#include <string>
class CreditAccount :
	public Account
{
private:
	double credit; //–≈”√∂Ó∂»
	double rate;
	double fee;
	Accumulator acc;
public:
	CreditAccount();
	~CreditAccount();
	double getCredit() const { return credit; }
	void getAvailable() const { return; }
	void getDebt() const {}
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	void deposit(const Date & dat, const double & amount, std::string desc);
	void withdraw(const Date & dat, const double & amount, std::string desc);
	void settle(const Date & dat);
};

