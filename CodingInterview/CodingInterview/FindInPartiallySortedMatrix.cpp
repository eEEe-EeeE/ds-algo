
bool findInPartiallySortedMatrix(const int arr[], int rows, int columns, int number) {
	if (arr == nullptr)
		return false;

	if (number < arr[0] || number > arr[rows * columns - 1])
		return false;

	int index = columns - 1;
	while (index != (rows - 1) * columns) {
		if (number < arr[index]) {
			if (index % columns == 0)
				return false;
			else
				--index;
		}
		else if (number > arr[index]) {
			if (index >= (rows - 1) * columns)
				return false;
			else
				index += columns;
		}
		else
			return true;
	}
	if (index == (rows - 1) * columns && number == arr[index])
		return true;
	else
		return false;
}