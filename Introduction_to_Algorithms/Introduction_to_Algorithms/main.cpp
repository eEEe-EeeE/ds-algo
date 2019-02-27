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
	vector<int> diff;
	for (int i = 1; i != shares.size(); ++i) {
		diff.push_back(shares[i] - shares[i - 1]);
	}
	
	//vector<int> res(maxsubarray1(shares));
	//for (auto & x : res)
	//	cout << x << ",";
	//cout << endl;
	//MaxSubarray arr = findmaximumsubarray(diff, 0, diff.size() - 1);
	//cout << arr.getLeft() << ", " << arr.getRight() << ", " << arr.getSum() << endl;
	int n = 5;
	int * p = new int[n] {};
	cout << p[4] << endl;

	system("pause");
}