#pragma once
#include <string>
#include "Date.h"
class Account {
private:
	std::string id;
	double balance;
	//���������˻��������
	static double total;
protected:
	Account(const Date & dat, const std::string & id);
	~Account();
	//�ı��˻����ʹ�ӡ���仯
	void record(const Date & dat, const double & amount, const std::string & desc);
	//��ӡ������Ϣ
	void error(const std::string & msg) const;
public:
	std::string getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	void show() const;

};

