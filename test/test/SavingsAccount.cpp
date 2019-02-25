#include "SavingsAccount.h"

using namespace std;

double SavingsAccount::total = 0;

void SavingsAccount::record(const Date & date, double amount, const string & desc) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = round(amount * 100) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

double SavingsAccount::accumulate(const Date & date) {
	return accumulation + balance * date.distance(lastDate);
}

void SavingsAccount::show() const {
	cout << id << "\tBalance: " << balance;
}

void SavingsAccount::error(const string & err) const {
	cout << "Error(#" << id << "): " << err << endl;
}

//´æÇ®
void SavingsAccount::deposit(const Date & date, double amount, const string & desc) {
	if (amount <= 0) {
		cout << "Amount must be positive." << endl;
		return;
	}
	record(date, amount, desc);
}

//È¡Ç®
void SavingsAccount::withdraw(const Date & date, double amount, const string & desc) {
	if (balance <= 0) {
		cout << "Not enough money." << endl;
		return;
	}
	record(date, -amount, desc);
}


void SavingsAccount::settle(const Date & date) {
	double interest = accumulate(date) * rate / date.distance(Date(date.getYear() - 1, date.getMonth(), date.getDay()));
	interest = round(interest * 100) / 100;
	if (interest != 0)
		record(date, interest, "interest");
	accumulation = 0;
}





