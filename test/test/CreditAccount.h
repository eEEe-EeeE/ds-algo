#pragma once
#include "Account.h"
#include "Accumulator.h"

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
};

