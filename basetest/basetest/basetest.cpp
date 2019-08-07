// basetest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "basetest.h"

#include "A.h"

using namespace std;


int main() {

	//Date date(2008, 11, 1); //起始日期
	////创建几个账户
	//SavingsAccount sa1(date, "S2755217", 0.015);
	//SavingsAccount sa2(date, "02342342", 0.015);
	//CreditAccount cr1(date, "C5392394", 10000, 0.015, 50);
	//Account * account[] = { &sa1, &sa2, &cr1 };
	//const int n = sizeof(account) / sizeof(Account *);

	//startUp(date, account, n);

	/*Array<int> a(10);
	printPrime(10);*/

	// confirm a stream's state

	//const vector<int> nums{ 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };

	//vector<int> res1 = SortAlgo().bubbleSort(nums);
	//for (auto& e : res1) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res2 = SortAlgo().shellSort(nums);
	//for (auto& e : res2) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res3 = SortAlgo().mergeSort(nums);
	//for (auto& e : res3) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res4 = SortAlgo().heapSort(nums);
	//for (auto& e : res4) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res5 = SortAlgo().countingSort(nums);
	//for (auto& e : res5) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res6 = SortAlgo().bucketSort(nums);
	//for (auto& e : res6) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res7 = SortAlgo().radixSort(nums);
	//for (auto& e : res7) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res8 = SortAlgo().insertionSort(nums);
	//for (auto& e : res8) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res9 = SortAlgo().selectionSort(nums);
	//for (auto& e : res9) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> res0 = SortAlgo().quickSort(nums);
	//for (auto& e : res0) {
	//	cout << e << " ";
	//}
	//cout << endl;

	cout << solution();
	
}

bool solution() {
	int x = INT_MIN;
	int num = x;
	int rev = 0;
	if (num < 0)
		return false;
	else {
		while (num != 0) {
			if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && num % 10 > INT_MAX % 10)
				return false;
			if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && num % 10 < INT_MIN % 10)
				return false;
			rev = rev * 10 + num % 10;
			num /= 10;
		}
	}
	if (rev == x)
		return true;
	else
		return false;
}

bool isPalindromic(string s, int left, int right) {
	while (left <= right) {
		if (s[left] != s[right])
			return false;
		++left;
		--right;
	}
	return true;
}



void printPrime(const int& n) {
	Array<int> arr(0);
	bool isPrime = true;
	int count = 0;
	for (auto num = 2; num <= n; ++num) {
		isPrime = true;
		for (auto j = 0; j < count; ++j) {
			if (num % arr[j] == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			if (count == arr.getSize())
				arr.reSize(arr.getSize() * 2 + 1);
			arr[count++] = num;
		}
	}
	for (auto i = 0; i < arr.getSize(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}


int startUp(Date & date, Account * account[], const int& n) {

	char cmd = 0;
	do {
		cout << "date: ";
		date.show();
		cout << "\tTotal: " << Account::getTotal() << endl;
		cout << "(d)deposit, (w)withdraw, (s)show, (c)change day, (n)next month, (e)exit" << endl;
		cout << "command>";
		int index, day;
		double amount;
		string desc;

		cin >> cmd;
		switch (cmd) {
		case 'd': //存入现金
			cout << "account number: ";
			cin >> index;
			if (index < 0 || index > n - 1) {
				cout << "Transboundary." << endl;
				break;
			}
			cout << "deposit amount: ";
			cin >> amount;
			cout << "remarks: ";
			getline(cin, desc);
			getline(cin, desc); //默认以\n为终止符，读入的字符串不包括终止符
			account[index]->deposit(date, amount, desc);
			break;
		case 'w': //取出现金
			cout << "account number: ";
			cin >> index;
			if (index < 0 || index > n - 1) {
				cout << "Transboundary." << endl;
				break;
			}
			cout << "withdraw amount: ";
			cin >> amount;
			cout << "remarks: ";
			getline(cin, desc);
			getline(cin, desc); //默认以\n为终止符，读入的字符串不包括终止符
			account[index]->withdraw(date, amount, desc);
			break;
		case 's':
			for (int i = 0; i < n; ++i) {
				cout << '[' << i << ']';
				date.show();
				cout << '\t';
				account[index]->show();
				cout << endl;
			}
			break;
		case 'c':
			cout << "day = ";
			cin >> day;
			if (1 <= day && day <= date.getMaxDay()) {
				date = Date(date.getYear(), date.getMonth(), day);
			}
			else {
				cout << "illegal date." << endl;
			}
			break;
		case 'n':
			if (date.getMonth() == 12) {
				date = Date(date.getYear() + 1, 1, 1);
			}
			else {
				date = Date(date.getYear(), date.getMonth() + 1, 1);
			}
			for (int i = 0; i < n; ++i)
				account[i]->settle(date);
			break;
		default:
			break;
		}
		cout << endl;
	} while (cmd != 'e');
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
