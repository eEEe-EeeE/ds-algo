#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <Windows.h>
#include "myutility.h"

using namespace std;

int main() {

	vector<int> v = { 5,2,4,6,1,3 };
	insertsort2(v);
	for (auto & x : v)
		cout << x;
	cout << endl;

	system("pause");
}