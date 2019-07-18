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

	std::vector<T> bubbleSort(std::vector<T>& _arr) {
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

	std::vector<T> selectionSort(std::vector<T>& _arr) {
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
	
	std::vector<T> insertionSort(std::vector<T>& _arr) {
		std::vector<T> arr(_arr);
		T cur_e;
		for (int i = 1; i != arr.size(); ++i) {
			cur_e = arr[i];
			int j = 0;
			for (j = i - 1; j >= 0 && cur_e <= arr[j]; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = cur_e;
		}
	}

	std::vector<T> shellSort(std::vector<T>& _arr) {
		std::vector<T> arr(_arr);
		// 增量序列有多少个增量就进行多少趟排序
		for (int gap = arr.size(); gap >= 1; gap = gap / 3 + 1) {
			for (int i = gap; i != arr.size(); ++i) {
				T cur_e = arr[i];
				int j = 0;
				for (j = i - gap; j >= 0 && cur_e < arr[j]; j -= gap) {
					arr[j + gap] = arr[j];
				}
				if (i != j + gap)
					arr[j + gap] = cur_e;
			}
			if (gap == 1)
				break;
		}
		return arr;
	}

};


#endif