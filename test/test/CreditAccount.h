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
	CreditAccount(const Date & dat, const std::string & id, const double & cred, const double & rate, const double & fee);
	~CreditAccount();
	double getDebt() const { return acc.getValue(); }
	double getCredit() const { return credit; }
	double getAvailableCredit() const { return getCredit() - getDebt(); }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	void deposit(const Date & dat, const double & amount, const std::string & desc);
	void withdraw(const Date & dat, const double & amount, const std::string & desc);
	void settle(const Date & dat);
	void show() const {
		show();
		std::cout << "\t#Credit: " << getCredit();
	}
};

