#include "myutility.h"
#include <limits>
using namespace std;

int myrandom(int b, int e) {
	random_device rd;  // 将用于为随机数引擎获得种子
	mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
	uniform_int_distribution<> dis(b, e);
	return dis(gen);
}

void insertsort1(vector<int> & v, bool mode) {
	if (mode == true) {
		for (auto cur = 1; cur < v.size(); ++cur) {
			auto key = v[cur];
			auto ptr = cur - 1;
			while (ptr >= 0 && v[ptr] > key) {
				v[ptr + 1] = v[ptr];
				--ptr;
			}
			v[ptr + 1] = key;
		}
	}
	else {
		// 非升排序
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
// 加入二分查找的插入排序，并不能改进最坏情况的时间。
void insertsort2(vector<int> & v) {
	for (auto cur = 1; cur < v.size(); ++cur) {
		auto key = v[cur];
		auto begin = 0;
		auto end = cur - 1;
		auto mid = (begin + end) / 2;
		while (begin <= end) {
			if (key >= v[mid]) {
				if (begin == end)
					break;
				if (key < v[mid + 1])
					break;
				else {
					begin = mid + 1;
					mid = (begin + end) / 2;
				}
			}
			else {
				if (mid == 0) {
					mid = -1;
					break;
				}
				end = mid - 1;
				mid = (begin + end) / 2;
			}
		}
		auto ptr = cur - 1;
		while (ptr > mid) {
			v[ptr + 1] = v[ptr];
			--ptr;
		}
		v[mid + 1] = key;
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

void merge1(vector<int> & v, int p, int q, int r) {
	vector<int> left;
	vector<int> right;
	for (auto i = p; i <= q; ++i)
		left.push_back(v[i]);
	left.push_back(numeric_limits<int>::max());
	for (auto j = q + 1; j <= r; ++j)
		right.push_back(v[j]);
	right.push_back(numeric_limits<int>::max());
	for (auto i = 0, j = 0, k = p; k <= r; ++k) {
		if (left[i] < right[j]) {
			v[k] = left[i];
			++i;
		}
		else {
			v[k] = right[j];
			++j;
		}
	}
}

void merge2(vector<int> & v, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> left;
	vector<int> right;
	for (auto i = p; i <= q; ++i)
		left.push_back(v[i]);
	for (auto j = q + 1; j <= r; ++j)
		right.push_back(v[j]);
	for (auto i = 0, j = 0, k = p; k <= r; ++k) {
		if (i > n1 - 1) {
			v[k] = right[j];
			++j;
		}
		else if (j > n2 - 1) {
			v[k] = left[i];
			++i;
		}
		else if (left[i] < right[j]) {
			v[k] = left[i];
			++i;
		}
		else {
			v[k] = right[j];
			++j;
		}
	}
}

void mergesort(vector<int> & v, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(v, p, q);
		mergesort(v, q + 1, r);
		merge2(v, p, q, r);
	}
}

int binarysearch1(vector<int> & v, int p, int r, int num) {
	if (p <= r) {
		int q = (p + r) / 2;
		if (num == v[q])
			return q;
		else if (num < v[q])
			return binarysearch1(v, p, q - 1, num);
		else
			return binarysearch1(v, q + 1, r, num);
	}
	else
		return -1;
}

vector<int> maxsubarray1(const vector<int> & v) {
	auto begin = 0;
	auto end = 1;
	auto max = 0;
	vector<int> res(2);
	while (begin != v.size() - 1) {
		while (end != v.size()) {
			if (v[end] - v[begin] > max) {
				max = v[end] - v[begin];
				res[0] = begin;
				res[1] = end;
			}
			++end;
		}
		++begin;
		end = begin + 1;
	}
	return res;
}

//最大子数组
MaxSubarray findmaxcrossing(const vector<int> & v, int p, int q, int r) {
	int left_sum = numeric_limits<int>::min();
	int left_max = q;
	int sum = 0;
	for (int i = q; i >= 0; --i) {
		sum += v[i];
		if (sum > left_sum) {
			left_sum = sum;
			left_max = i;
		}
	}
	int right_sum = numeric_limits<int>::min();
	int right_max = q;
	sum = 0;
	for (int j = q + 1; j < v.size(); ++j) {
		sum += v[j];
		if (sum > right_sum) {
			right_sum = sum;
			right_max = j;
		}
	}
	MaxSubarray arr(left_max, right_max, left_sum + right_sum);
	return arr;
}

MaxSubarray findmaximumsubarray(const vector<int> & v, int p, int r) {
	if (p == r) {
		MaxSubarray arr(p, r, v[p]);
		return arr;
	}
	else {
		MaxSubarray left, mid, right;
		int q = (p + r) / 2;
		left = findmaximumsubarray(v, p, q);
		mid = findmaxcrossing(v, p, q, r);
		right = findmaximumsubarray(v, q + 1, r);
		if (left.getSum() > right.getSum() && left.getSum() > mid.getSum())
			return left;
		else if (right.getSum() > left.getSum() && right.getSum() > mid.getSum())
			return right;
		else
			return mid;
	}
}

//矩阵乘法
Matrix Matrix::operator * (const Matrix & m) {
	if (nColumns != m.nRows)
		exit(1);
	Matrix c(nRows, m.nColumns);
	for (int i = 0; i < nRows; ++i)
		for (int j = 0; j < m.nColumns; ++j)
			for (int k = 0; k < nColumns; ++k)
				c[i * nColumns + j] += lpBuf[]
}
