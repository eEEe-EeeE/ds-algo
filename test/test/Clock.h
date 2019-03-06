#pragma once
#include <iostream>
#include <string>

class Clock
{
private:
	int hour;
	int minute;
	int second;
	void error(const std::string & msg) const {
		std::cout << msg << std::endl;
	}
public:
	Clock(const int & hour, const int & minute, const int & second);
	~Clock();
	Clock & operator ++ ();
	Clock operator ++ (int);
	void showTime() const;
};

