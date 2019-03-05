#include "CreditAccount.h"

using namespace std;

CreditAccount::CreditAccount(const Date & dat, const string & id, const double & cred, const double & rate, const double & fee) :
	Account(dat, id), credit(cred), rate(rate), fee(fee), acc(dat, 0)
{
}

CreditAccount::~CreditAccount()
{
}


void CreditAccount::deposit(const Date & dat, const double & amount, const string & desc) {
	record(dat, amount, desc);
	acc.change(dat, amount);
}

void CreditAccount::withdraw(const Date & dat, const double & amount, const string & desc) {
	if (amount <= getBalance()) {
		record(dat, -amount, desc);
		acc.change(dat, amount);
	}
	else
		error("Sorry, your credit is running low.");
}

void CreditAccount::settle(const Date & dat) {
	
}