#ifndef _CODINGINTERVIEW_H
#define _CODINGINTERVIEW_H
#include "LinkedList.h"
template <class T>
inline std::size_t arrayLength(T& arr) {
	return sizeof(arr) / sizeof(arr[0]);
}
bool duplicationInArray(int arr[], const int arrLength, int* dup);
bool duplicationInArrayNoEdit1(const int arr[], const int length);
int duplicationInArrayNoEdit2(const int arr[], const int arrLength);
bool findInPartiallySortedMatrix(const int arr[], int rows, int columns, int number);
void replaceSpaces(char str[], const int arrLength);
void printListInReversedOrder(LinkedList* pHead);
#endif