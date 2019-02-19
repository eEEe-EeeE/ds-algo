#include "myutility.h"
using namespace std;

int myrandom(int b, int e) {
	random_device rd;  // ������Ϊ���������������
	mt19937 gen(rd()); // �Բ��ֱ�׼ mersenne_twister_engine
	uniform_int_distribution<> dis(b, e);
	return dis(gen);
}

void insertsort(vector<int> & v) {
	for (auto ptr = v.begin() + 1; ptr < v.end(); ++ptr) {
		auto key = *ptr;
		auto count = ptr - 1;
		for ( ; count != v.begin() && *count > key; --count) {
			*(count + 1) = *count;
		}
		if (count != v.begin())
			*(count + 1) = key;
		else {
			if (*count > key) {
				*(count + 1) = *count;
				*count = key;
			}
			else
				*(count + 1) = key;
		}
	}
}
