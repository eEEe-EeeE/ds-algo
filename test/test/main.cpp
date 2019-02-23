#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "BAManagement.h"

using namespace std;

int main() {

	//���������˻�
	BAManagement sa0(1, 21325302, 0.015);
	BAManagement sa1(1, 58320212, 0.015);

	//������Ŀ
	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);

	//�������90�쵽�����еļ�Ϣ�գ����������˻�����Ϣ
	sa0.settle(90);
	sa1.settle(90);

	//��������˻���Ϣ
	sa0.show();	cout << endl;
	sa1.show();	cout << endl;
	cout << BAManagement::getTotal() << endl;


	system("pause");
}