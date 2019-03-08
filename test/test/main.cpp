#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Complex.h"
#include "Clock.h"
using namespace std;

class Base1 { //基类Base1定义
public:
	virtual void display() const {
		cout << "Base1::display()" << endl;
	}
};
class Base2 : public Base1 { //公有派生类Base2定义
public:
	virtual void display() const {
		cout << "Base2::display()" << endl;
	}
};
class Derived : public Base2 { //公有派生类Derived定义
public:
	virtual void display() const {
		cout << "Derived::display()" << endl;
	}
};
void fun(Base1 *ptr) {  //参数为指向基类对象的指针
	ptr->display();     //"对象指针->成员名"
}

int main() {

	Date date(2008, 11, 1); //起始日期
	//创建几个账户
	SavingsAccount sa1(date, "S2755217", 0.015);
	SavingsAccount sa2(date, "02342342", 0.015);
	CreditAccount cr1(date, "C5392394", 10000, 0.015, 50);
	Account * account[] = { &sa1, &sa2, &cr1 };
	const int n = sizeof(account) / sizeof(Account *);

	cout << "(d)deposit, (w)withdraw, (s)show, (c)change day, (n)next month, (e)exit" << endl;

	char cmd = 0;
	do {
		cout << "date: ";
		date.show();
		cout << "\tTotal: " << Account::getTotal() << endl;
		cout << "command>";
		int index, day;
		double amount;
		string desc;

		cin >> cmd;
		switch (cmd) {
		case 'd': //存入现金
			cout << "account number: ";
			cin >> index;
			cout << endl << "deposit amount: ";
			cin >> amount;
			cout << endl << "remarks: ";
			getline(cin, desc);
			account[index]->deposit(date, amount, desc);
			break;
		case 'w': //取出现金
			cout << "account number: ";
			cin >> index;
			cout << endl << "withdraw amount: ";
			cin >> amount;
			cout << endl << "remarks: ";
			account[index]->withdraw(date, amount, desc);
			getline(cin, desc);
			break;
		case 's':
			break;
		}
	} while (true);




	system("pause");
}