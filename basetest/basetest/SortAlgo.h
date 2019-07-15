#ifndef SORTALGO_H
#define SORTALGO_H
#include <vector>

template <class T>
class SortAlgo {
private:
	void swap(T& e1, T& e2) {
		T temp;
		temp = e1;
		e1 = e2;
		e2 = temp;
	}
public:
	std::vector<T> bubbleSort(std::vector<T>& _arr);
	std::vector<T> selectionSort(std::vector<T>& _arr);
	std::vector<T> insertionSort(std::vector<T>& _arr);
};

#endif