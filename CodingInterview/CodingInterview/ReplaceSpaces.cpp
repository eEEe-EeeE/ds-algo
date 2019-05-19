#include <cstring>
void replaceSpaces(char str[], const int arrLength) {
	if (str == nullptr || arrLength == 0)
		return;

	int reserve = 0;
	for (int index = 0; index < arrLength; ++index) {
		if (str[index] == ' ')
			reserve += 2;
	}
	
	if (arrLength < strlen(str) + reserve) {
		return;
	}

	for (int index = strlen(str); index >= 0; --index) {
		if (str[index] != ' ') {
			if (reserve == 0)
				break;
			else
				str[index + reserve] = str[index];
		}
		else {
			reserve -= 2;
			memcpy(str + index + reserve, "%20", 3);
		}
	}
}