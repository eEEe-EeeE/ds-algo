#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "SavingsAccount.h"
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

	//Date date(2008, 11, 1);	//起始日期
	////建立几个账户
	//SavingsAccount accounts[] = {
	//	SavingsAccount(date, "S3755217", 0.015),
	//	SavingsAccount(date, "02342342", 0.015)
	//};
	//const int n = sizeof(accounts) / sizeof(SavingsAccount); //账户总数
	////11月份的几笔账目
	//accounts[0].deposit(Date(2008, 11, 5), 5000, "salary");
	//accounts[1].deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
	////12月份的几笔账目
	//accounts[0].deposit(Date(2008, 12, 5), 5500, "salary");
	//accounts[1].withdraw(Date(2008, 12, 20), 4000, "buy a laptop");

	////结算所有账户并输出各个账户信息
	//cout << endl;
	//for (int i = 0; i < n; i++) {
	//	accounts[i].settle(Date(2009, 1, 1));
	//	accounts[i].show();
	//	cout << endl;
	//}
	//cout << "Total: " << SavingsAccount::getTotal() << endl;
	
	Base1 base1;    //声明Base1类对象
	Base2 base2;    //声明Base2类对象
	Derived derived;    //声明Derived类对象

	fun(&base1);    //用Base1对象的指针调用fun函数
	fun(&base2);    //用Base2对象的指针调用fun函数
	fun(&derived);     //用Derived对象的指针调用fun函数

	system("pause");
}