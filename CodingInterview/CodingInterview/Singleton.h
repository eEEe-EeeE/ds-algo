#pragma once
class Singleton {
private:
	static Singleton* st;
	Singleton() {}
public:
	static Singleton* getInstance() {
		if (st == nullptr)
			st = new Singleton();
		return st;
	}
};
