#include "BAManagement.h"
#include <cmath>
#include <iostream>
using namespace std;

double BAManagement::total = 0;

void BAManagement::show() {
	cout << "id: " << id << endl <<
		"balance: " << balance << endl <<
		"rate: " << rate << endl;
}

//´æÇ®
void BAManagement::deposit(int date, double amount) {
	if (amount <= 0) {
		cout << "Amount must be positive." << endl;
		return;
	}
	record(date, amount);
	cout << "id : " << id << endl;
	cout << amount << "Yuan deposited." << endl;
	cout << "balance : " << balance << endl;
}

//È¡Ç®
void BAManagement::withdraw(int date, double amount) {
	if (balance <= 0) {
		cout << "Not enough money." << endl;
		return;
	}
	record(date, -amount);
	cout << "id : " << id << endl;
	cout << amount << "Yuan withdrawed." << endl;
	cout << "balance : " << balance << endl;
}


void BAManagement::settle(int date) {
	double interest = accumulate(date) * rate / 365;
	interest = round(interest * 100) / 100;
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
	cout << "id : " << id << endl;
	cout << "interest : " << interest << endl;
}


void BAManagement::record(int date, double amount) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = round(amount * 100) / 100;
	balance += amount;
	total += amount;
}


double BAManagement::accumulate(int date) {
	return accumulation + balance * (date - lastDate);
}



