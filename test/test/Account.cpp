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
	//存取金额四舍五入
	double amount_round = round(amount * 100) / 100;
	//改变余额
	balance += amount_round;
	//所有账户总余额
	total += amount_round;
	//打印余额变化
	cout << "\t#" << id << "\t" << amount_round << "\tbalance: " << balance << "\t" << desc;
}

void Account::error(const string & msg) const {
	cout << msg;
}

void Account::show() const {
	//显示卡上余额
	cout << id << "\tBalance: " << balance;
}

