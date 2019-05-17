#include "Utils.h"
#include <iostream>
bool duplicationInArray(int arr[], int arrLength, int* duplication) {
	if (Utils<int>::maxInArray(arr, arrLength) >= arrLength) {
		std::cout << "arr's max data is error." << std::endl;
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
