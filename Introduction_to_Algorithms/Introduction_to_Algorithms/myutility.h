#ifndef MYUTILITY_H
#define MYUTILITY_H

#include <random>
#include <vector>

//最大子数组
class MaxSubarray {
private:
	int left;
	int right;
	int sum;
public:
	MaxSubarray()
		:left(0), right(0), sum(0) {}
	MaxSubarray(int l, int r, int s)
		:left(l), right(r), sum(s) {}
	MaxSubarray(const MaxSubarray & ms) {
		left = ms.left;
		right = ms.right;
		sum = ms.sum;
	}
	MaxSubarray & operator = (const MaxSubarray & ms) {
		if (this != &ms) {
			left = ms.left;
			right = ms.right;
			sum = ms.sum;
		}
		return *this;
	}
	int getLeft() { return left; }
	int getRight() { return right; }
	int getSum() { return sum; }
};

//矩阵
class Matrix {
private:
	int nRows;
	int nColumns;
	int* lpBuf;
public:
	Matrix()
		:nRows(0), nColumns(0), lpBuf(nullptr) {}
	Matrix(const int r, const int c)
		:nRows(r), nColumns(c) {
		lpBuf = new int[r * c]{};
	}
	~Matrix() {
		if (lpBuf != nullptr)
			delete[] lpBuf;
	}
	Matrix operator [] (int n) {};
	Matrix operator * (const Matrix & m);
};

int myrandom(int b, int e);
void insertsort1(std::vector<int> & v, bool mode = true);
void insertsort2(std::vector<int> & v);
void selectsort(std::vector<int> & v);
void mergesort(std::vector<int> & v, int p, int r);
int binarysearch1(std::vector<int> & v, int p, int r, int num);
std::vector<int> maxsubarray1(const std::vector<int> & v);
MaxSubarray findmaximumsubarray(const std::vector<int> & v, int p, int r);

#endif