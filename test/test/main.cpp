#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "SavingsAccount.h"
#include "Complex.h"
#include "Clock.h"
using namespace std;

class Base1 { //����Base1����
public:
	virtual void display() const {
		cout << "Base1::display()" << endl;
	}
};
class Base2 : public Base1 { //����������Base2����
public:
	virtual void display() const {
		cout << "Base2::display()" << endl;
	}
};
class Derived : public Base2 { //����������Derived����
public:
	virtual void display() const {
		cout << "Derived::display()" << endl;
	}
};
void fun(Base1 *ptr) {  //����Ϊָ���������ָ��
	ptr->display();     //"����ָ��->��Ա��"
}

int main() {

	//Date date(2008, 11, 1);	//��ʼ����
	////���������˻�
	//SavingsAccount accounts[] = {
	//	SavingsAccount(date, "S3755217", 0.015),
	//	SavingsAccount(date, "02342342", 0.015)
	//};
	//const int n = sizeof(accounts) / sizeof(SavingsAccount); //�˻�����
	////11�·ݵļ�����Ŀ
	//accounts[0].deposit(Date(2008, 11, 5), 5000, "salary");
	//accounts[1].deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
	////12�·ݵļ�����Ŀ
	//accounts[0].deposit(Date(2008, 12, 5), 5500, "salary");
	//accounts[1].withdraw(Date(2008, 12, 20), 4000, "buy a laptop");

	////���������˻�����������˻���Ϣ
	//cout << endl;
	//for (int i = 0; i < n; i++) {
	//	accounts[i].settle(Date(2009, 1, 1));
	//	accounts[i].show();
	//	cout << endl;
	//}
	//cout << "Total: " << SavingsAccount::getTotal() << endl;
	
	Base1 base1;    //����Base1�����
	Base2 base2;    //����Base2�����
	Derived derived;    //����Derived�����

	fun(&base1);    //��Base1�����ָ�����fun����
	fun(&base2);    //��Base2�����ָ�����fun����
	fun(&derived);     //��Derived�����ָ�����fun����

	system("pause");
}