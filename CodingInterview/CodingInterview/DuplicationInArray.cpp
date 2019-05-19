#include <iostream>
bool duplicationInArray(int arr[], const int arrLength, int* duplication) {
	if (arr == nullptr || arrLength <= 1)
		return false;

	for (int index = 0; index < arrLength; ++index) {
		if (arr[index] < 0 || arr[index] >= arrLength)
			return false;
	}

	for (int index = 0; index < arrLength - 1; ++index) {
		if (arr[index] == index) {
			continue;
		}
		else
		{
			if (arr[index] != arr[arr[index]]) {
				int temp = arr[index];
				arr[index] = arr[arr[index]];
				arr[temp] = temp;
				--index;
			}
			else {
				*duplication = arr[index];
				return true;
			}
		}
	}
	return false;
}
