#include "Date.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace {
	const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

Date::Date(int year, int month, int day)
	:year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "Invalid date : ";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totalDays = 365 * years + years / 4 - years / 100 + years / 400 +
		DAYS_BEFORE_MONTH[month - 1] + day;
	if (isLeapYear() && month > 2)
		++totalDays;
}

Date::~Date()
{
}

int Date::operator - (const Date & rth) const {
	return totalDays - rth.totalDays;
}

int Date::getMaxDay() const {
	if (isLeapYear() && month == 2)
		return 29;
	else
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

bool Date::isLeapYear() const {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void Date::show() const {
	cout << getYear() << "-" << getMonth() << "-" << getDay();
}