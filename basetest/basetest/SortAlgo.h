#ifndef SORTALGO_H
#define SORTALGO_H
#include <vector>

template <class T>
class SortAlgo {
private:

	typedef typename std::vector<T>::iterator vector_iterator;

	void swap(T& e1, T& e2) {
		T temp;
		temp = e1;
		e1 = e2;
		e2 = temp;
	}

	int maxElementIndex(const std::vector<T>& arr) {
		int max_index = 0;
		for (int index = 0; index != arr.size(); ++index) {
			if (arr[index] > arr[max_index])
				max_index = index;
		}
		return max_index;
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
		// ���������ж��ٸ������ͽ��ж���������
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

	std::vector<T> mergeSort(const std::vector<T>& _arr) {
		const std::vector<T>& arr(_arr);
		auto&& mid_iter = arr.begin() + floor((arr.end() - arr.begin()) / 2);
		std::vector<T> left_seq(arr.begin(), mid_iter);
		std::vector<T> right_seq(mid_iter, arr.end());
		if (arr.size() < 2)
			return arr;
		return merge(mergeSort(left_seq), mergeSort(right_seq));
	}

	std::vector<T> merge(const std::vector<T>& left_seq, const std::vector<T>& right_seq) {
		std::vector<T> arr;
		auto&& left_iter = left_seq.begin();
		auto&& right_iter = right_seq.begin();
		int cnt = 0;
		int arr_size = left_seq.size() + right_seq.size();
		while (cnt < arr_size) {
			if (left_iter == left_seq.cend()) {
				while (right_iter != right_seq.cend()) {
					arr.push_back(*right_iter);
					++cnt;
					++right_iter;
				}
			}
			else if (right_iter == right_seq.cend()) {
				while (left_iter != left_seq.cend()) {
					arr.push_back(*left_iter);
					++cnt;
					++left_iter;
				}
			}
			else {
				if (*left_iter <= *right_iter) {
					arr.push_back(*left_iter);
					++cnt;
					++left_iter;
				}
				else {
					arr.push_back(*right_iter);
					++cnt;
					++right_iter;
				}
			}
		}
		return arr;
	}

	// ������������ ***�ص�***
	std::vector<T> quickSort(const std::vector<T>& _arr) {
		std::vector<T> arr(_arr);
		qsort(arr, arr.begin(), arr.end());
		return arr;
	}

	void qsort(std::vector<T>& arr, vector_iterator left, vector_iterator right) {
		if (right - left > 1) {
			auto pivot = partition(arr, left, right);
			qsort(arr, left, pivot - 1); // β�����
			qsort(arr, pivot, right); //β�����
		}
	}

	vector_iterator partition(std::vector<T>& arr, vector_iterator left, vector_iterator right) {
		auto pivot = left + floor((right - left) / 2); // ��׼�������ѡȡ
		swap(*left, *pivot); // �ѻ�׼��������ߣ��Ա�������׶�λ����׼
		pivot = left;
		auto boundary = left; // boundary��β�������
		for (auto iter = left; iter != right; ++iter) {
			if (*iter <= *pivot) {
				if (iter - boundary > 0) {
					swap(*iter, *boundary);
				}
				++boundary;
			}
		}
		if (boundary - left != 1)
			swap(*pivot, *(boundary - 1));
		return boundary;
	}

	std::vector<T> heapSort(const std::vector<T>& _arr) {
		std::vector<T> arr(_arr);
		buildMaxHeap(arr);
		for (int index = arr.size() - 1; index > 0; --index) {
			swap(arr[0], arr[index]);
			heapify(arr, index, 0);
		}
		return arr;
	}

	void heapify(std::vector<T>& arr, int arrLen, int parent_index) {
		int left_child = 2 * parent_index + 1;
		int right_child = 2 * parent_index + 2;
		int largest = parent_index;
		if (left_child < arrLen && arr[left_child] > arr[largest])
			largest = left_child;
		if (right_child < arrLen && arr[right_child] > arr[largest])
			largest = right_child;

		if (parent_index != largest) {
			swap(arr[largest], arr[parent_index]);
			heapify(arr, arrLen, largest);
		}
	}

	void buildMaxHeap(std::vector<T>& arr) {
		for (auto index = floor(arr.size() / 2); index >= 0; --index) {
			heapify(arr, arr.size(), index);
		}
	}

	std::vector<T> countingSort(const std::vector<T>& _arr) {
		std::vector<T> arr(_arr.size(), 0);
		int max_index = maxElementIndex(_arr);
		T max_elem = _arr[max_index];
		std::vector<T> countingArr(max_elem + 1, 0);
		for (int index = 0; index < _arr.size(); ++index) {
			countingArr[_arr[index]] = countingArr[_arr[index]] + 1;
		}
		for (int index = 0; index < countingArr.size() - 1; ++index) {
			countingArr[index + 1] += countingArr[index];
		}
		for (int index = arr.size() - 1; index >= 0; --index) {
			arr[countingArr[_arr[index]] - 1] = _arr[index];
			--countingArr[_arr[index]];
		}
		return arr;
	}

};


#endif