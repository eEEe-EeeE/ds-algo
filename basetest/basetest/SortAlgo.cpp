#include "SortAlgo.h"

template <class T>
std::vector<T> SortAlgo<T>::bubbleSort(std::vector<T>& _arr) {
	std::vector<T> arr(_arr);
	for (int i = 1; i != arr.size(); ++i) {
		for (int j = 0; j != arr.size() - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;
}

template <class T>
std::vector<T> SortAlgo<T>::selectionSort(std::vector<T>& _arr) {
	std::vector<T> arr(_arr);
	int min_e = 0;
	for (int i = 1; i != arr.size(); ++i) {
		for (int j = i - 1; j != arr.size(); ++j) {
			if (arr[j] < arr[min_e])
				min_e = j;
		}
		swap(arr[i - 1], arr[min_e]);
	}
	return arr;
}

template <class T>
std::vector<T> SortAlgo<T>::insertionSort(std::vector<T>& _arr) {
	std::vector<T> arr(_arr);
	T cur_e;
	for (int i = 1; i != arr.size(); ++i) {
		cur_e = arr[i];
		for (int j = i - 1; j != -1 && cur_e <= arr[j]; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = cur_e;
	}
}