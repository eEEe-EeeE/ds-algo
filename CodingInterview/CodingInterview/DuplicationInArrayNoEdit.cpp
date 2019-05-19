
bool duplicationInArrayNoEdit1(const int arr[], const int arrLength) {
	if (arr == nullptr || arrLength <= 1)
		return false;

	for (int index = 0; index < arrLength; ++index) {
		if (arr[index] < 0 || arr[index] >= arrLength)
			return false;
	}

	int* arr2 = new int[arrLength] {};
	for (int index = 0; index < arrLength; ++index) {
		arr2[index] = -1;
	}
	for (int index = 0; index < arrLength; ++index) {
		if (arr[index] == arr2[arr[index]]) {
			return true;
		}
		else {
			arr2[arr[index]] = arr[index];
		}
	}
	return false;
}

int duplicationInArrayNoEdit2(const int arr[], const int arrLength) {
	// 数组长度n+1，数据范围1~n
	if (arr == nullptr || arrLength <= 1)
		return -1;

	int start = 1;
	int end = arrLength - 1;
	int middle;
	while (start <= end) {
		middle = start + ((end - start) >> 2);
		int count = 0;
		for (int index = 0; index < arrLength; ++index) {
			if (arr[index] >= start && arr[index] <= middle)
				++count;
		}
		if (count > (middle - start) + 1) {
			if (start == end)
				return start;
			else
				end = middle;
		}
		else {
			start = middle + 1;
		}
	}
	return -1;
}