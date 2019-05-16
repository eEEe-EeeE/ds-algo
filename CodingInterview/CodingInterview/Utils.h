#ifndef _UTILS_H
#define _UTILS_H
template <class T, size_t N = 1>
class Utils {
private:

public:
	static size_t arrayLength(T& arr) {
		return sizeof(arr) / sizeof(arr[0]);
	}

	static T max(T v1, T v2) {
		return v1 > v2 ? v1 : v2;
	}

	static T maxInArray(T(&arr)[N]) {
		T max = arr[0];
		for (auto& elem : arr) {
			if (elem > max) {
				max = elem;
			}
		}
		return max;
	}

	static T maxInArray(T arr[], size_t length) {
		T max = arr[0];
		for (size_t index = 0; index < length; ++index) {
			T& elem = arr[index];
			if (elem > max) {
				max = elem;
			}
		}
		return max;
	}

};
#endif // !_UTILS_H
