#include "Account.h"
#include <iostream>

using namespace std;

double Account::total = 0;

Account::Account(const Date & dat, const std::string & id) :
	id(id), balance(0)
{
	cout << "id : " << id << "The account is created.";
}

Account::~Account()
{
}

void Account::record(const Date & dat, const double & amount, const string & desc) {
	//��ȡ�����������
	double amount_round = round(amount * 100) / 100;
	//�ı����
	balance += amount_round;
	//�����˻������
	total += amount_round;
	//��ӡ���仯
	cout << "\t#" << id << "\t" << amount_round << "\tbalance: " << balance << "\t" << desc;
}

void Account::error(const string & msg) const {
	cout << msg;
}

void Account::show() const {
	//��ʾ�������
	cout << id << "\tBalance: " << balance;
}

