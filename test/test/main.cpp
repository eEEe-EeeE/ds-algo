#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Complex.h"
#include "Clock.h"
#include "Array.h"

using namespace std;

void read(int *p, int n) {
	for (int i = 0; i < n; i++)
		cin >> p[i];
}

void printPrime(const int & n);
int startUp(Date & date, Account * account[], const int & n);

int main() {

	//Date date(2008, 11, 1); //起始日期
	////创建几个账户
	//SavingsAccount sa1(date, "S2755217", 0.015);
	//SavingsAccount sa2(date, "02342342", 0.015);
	//CreditAccount cr1(date, "C5392394", 10000, 0.015, 50);
	//Account * account[] = { &sa1, &sa2, &cr1 };
	//const int n = sizeof(account) / sizeof(Account *);

	//startUp(date, account, n);

	Array<int> a(10);
	printPrime(10);

	system("pause");
}

void printPrime(const int & n) {
	Array<int> arr(0);
	bool isPrime = true;
	int count = 0;
	for (auto num = 2; num <= n; ++num) {
		isPrime = true;
		for (auto j = 0; j < count; ++j) {
			if (num % arr[j] == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			if (count == arr.getSize())
				arr.reSize(arr.getSize() * 2);
			arr[count++] = num;
		}
	}
	for (auto i = 0; i < arr.getSize(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}


int startUp(Date & date, Account * account[], const int & n) {

	char cmd = 0;
	do {
		cout << "date: ";
		date.show();
		cout << "\tTotal: " << Account::getTotal() << endl;
		cout << "(d)deposit, (w)withdraw, (s)show, (c)change day, (n)next month, (e)exit" << endl;
		cout << "command>";
		int index, day;
		double amount;
		string desc;

		cin >> cmd;
		switch (cmd) {
		case 'd': //存入现金
			cout << "account number: ";
			cin >> index;
			if (index < 0 || index > n - 1) {
				cout << "Transboundary." << endl;
				break;
			}
			cout << "deposit amount: ";
			cin >> amount;
			cout << "remarks: ";
			getline(cin, desc);
			getline(cin, desc); //默认以\n为终止符，读入的字符串不包括终止符
			account[index]->deposit(date, amount, desc);
			break;
		case 'w': //取出现金
			cout << "account number: ";
			cin >> index;
			if (index < 0 || index > n - 1) {
				cout << "Transboundary." << endl;
				break;
			}
			cout << "withdraw amount: ";
			cin >> amount;
			cout << "remarks: ";
			getline(cin, desc);
			getline(cin, desc); //默认以\n为终止符，读入的字符串不包括终止符
			account[index]->withdraw(date, amount, desc);
			break;
		case 's':
			for (int i = 0; i < n; ++i) {
				cout << '[' << i << ']';
				date.show();
				cout << '\t';
				account[index]->show();
				cout << endl;
			}
			break;
		case 'c':
			cout << "day = ";
			cin >> day;
			if (1 <= day && day <= date.getMaxDay()) {
				date = Date(date.getYear(), date.getMonth(), day);
			}
			else {
				cout << "illegal date." << endl;
			}
			break;
		case 'n':
			if (date.getMonth() == 12) {
				date = Date(date.getYear() + 1, 1, 1);
			}
			else {
				date = Date(date.getYear(), date.getMonth() + 1, 1);
			}
			for (int i = 0; i < n; ++i)
				account[i]->settle(date);
			break;
		default:
			break;
		}
		cout << endl;
	} while (cmd != 'e');
	return 0;
}