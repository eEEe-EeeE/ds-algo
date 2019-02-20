#include "myutility.h"
#include <limits>
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


void selectsort(vector<int> & v) {
	auto i = 0;
	auto min = 0;
	while (i != v.size()) {
		auto min = i;
		for (auto j = i + 1; j != v.size(); ++j) {
			if (v[min] > v[j])
				min = j;
		}
		if (min != i) {
			auto temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
		++i;
	}
}


void mergesort(vector<int> & v, int p, int r) {
	numeric_limits<int>::max();
}