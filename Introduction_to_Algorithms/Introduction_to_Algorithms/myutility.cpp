#include "myutility.h"
using namespace std;

int myrandom(int b, int e) {
	random_device rd;  // 将用于为随机数引擎获得种子
	mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
	uniform_int_distribution<> dis(b, e);
	return dis(gen);
}

void insertsort(vector<int> & v, bool mode) {
	if (mode == true) {
		for (auto cur = v.begin() + 1; cur < v.end(); ++cur) {
			auto key = *cur;
			auto ptr = cur - 1;
			for (; ptr != v.begin() && *ptr > key; --ptr) {
				*(ptr + 1) = *ptr;
			}
			if (ptr == v.begin() && *ptr > key) {
				*(ptr + 1) = *ptr;
				*ptr = key;
			}
			else
				*(ptr + 1) = key;
		}
	}
	else {
		for (auto cur = v.begin() + 1; cur != v.end(); ++cur) {
			auto key = *cur;
			auto ptr = cur - 1;
			for (; ptr != v.begin() && *ptr < key; --ptr) {
				*(ptr + 1) = *ptr;
			}
			if (ptr == v.begin() && *ptr < key) {
				*(ptr + 1) = *ptr;
				*ptr = key;
			}
			else
				*(ptr + 1) = key;
		}
	}
}


