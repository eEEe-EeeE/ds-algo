#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <Windows.h>
#include "myutility.h"

using namespace std;

int main() {

	vector<int> v = { 5,2,4,6,1,3 };

	vector<int> shares = { 100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97 };

	
	vector<int> res(maxsubarray1(shares));
	for (auto & x : res)
		cout << x << ",";
	cout << endl;
	
	system("pause");
}