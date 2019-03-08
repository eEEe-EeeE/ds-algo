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
	acc.change(dat, getBalance());
}

void CreditAccount::withdraw(const Date & dat, const double & amount, const string & desc) {
	if (amount <= getAvailableCredit()) {
		record(dat, -amount, desc);
		acc.change(dat, getBalance());
	}
	else
		error("Sorry, your credit is running low.");
}

void CreditAccount::settle(const Date & dat) {
	if (dat.getDay() != 1) {
		error("Error in settlement date.");
	}
	else {
		double interest;
		interest = acc.getSum(dat) / dat.distance(Date(dat.getYear(), dat.getMonth() - 1, 1)) * getRate();
		if (interest != 0) {
			record(dat, interest, "interest");
			acc.reset(dat, getBalance());
		}
	}
}