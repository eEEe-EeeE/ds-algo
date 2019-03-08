#include "Clock.h"

using namespace std;

Clock::Clock(const int & hour, const int & minute, const int & second)
{
	if ((0 <= hour && hour <= 23) && (0 <= minute && minute <= 59) && (0 <= second && second <= 60)) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else
		error("Error in input parameters.");
}

Clock::~Clock()
{
}

Clock & Clock::operator ++ () {
	second += 1;
	if (second >= 60) {
		second = 0;
		minute += 1;
		if (minute >= 60) {
			minute = 0;
			hour += 1;
			hour %= 24;
		}
	}
	return *this;
}

Clock Clock::operator ++ (int) {
	Clock old = *this;
	++(*this);
	return old;
}

void Clock::showTime() const {
	cout << hour << ":" << minute << ":" << second << endl;
}