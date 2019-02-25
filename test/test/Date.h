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
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;
	bool isLeapYear() const {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	int distance(const Date & date) const {
		return totalDays - date.totalDays;
	}
	void show() const;
};


#endif