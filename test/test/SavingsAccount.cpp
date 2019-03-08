#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(const Date & dat, const string & id, const double & rate) :
	Account(dat, id), rate(rate), acc(dat, 0)
{}

SavingsAccount::~SavingsAccount()
{}

void SavingsAccount::deposit(const Date & dat, const double & amount, const string & desc) {
	record(dat, amount, desc);
	acc.change(dat, getBalance());
}

void SavingsAccount::withdraw(const Date & dat, const double & amount, const string & desc) {
	if (amount <= getBalance()) {
		record(dat, -amount, desc);
		acc.change(dat, getBalance());
	}
	else
		error("Sorry, your credit is running low.");
}

void SavingsAccount::settle(const Date & dat) {
	double interest;
	interest = acc.getSum(dat) / dat.distance(Date(dat.getYear() - 1, 1, 1)) * getRate();
	if (interest != 0) {
		record(dat, interest, "interest");
		acc.reset(dat, getBalance());
	}
}
