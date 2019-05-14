#ifndef _DATE_H
#define _DATE_H

#include <iostream>

class Date {
private:
	int year;
	int month;
	int day;
	int totalDays;

public:
	Date(int year, int month, int day);
	~Date();

	int operator - (const Date & rth) const;

	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;
	bool isLeapYear() const;
	void show() const;
};


#endif