#ifndef BAMANAGEMENT_H
#define BAMANAGEMENT_H
#include <cmath>
#include <iostream>

using namespace std;

class BAManagement {
public:
	BAManagement(int date, unsigned id, double rate, double amount = 0)
		:id(id), balance(amount), rate(rate), lastDate(date), accumulation(0) {
		cout << "id: " << id << " The account is created." << endl;
	}
	unsigned getId() const { return id; }
	double getBalance() const { return balance; }
	double getRate() const { return rate; }
	static double getTotal() { return total; }
	void show();
	void deposit(int date, double amount);
	void withdraw(int date, double amount);
	void settle(int date);

private:
	unsigned id;
	double balance;
	double rate;
	int lastDate;
	double accumulation;
	static double total;

	void record(int date, double amount);
	double accumulate(int date);

};
#endif