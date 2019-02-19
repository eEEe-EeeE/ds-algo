#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <Windows.h>
#include "myutility.h"

using namespace std;

int main() {

	vector<int> v = { 5,2,4,6,1,3 };
	insertsort(v);
	for (auto & x : v) {
		cout << x << endl;
	}
	insertsort(v, false);
	for (auto & x : v) {
		cout << x << endl;
	}
	system("pause");
}