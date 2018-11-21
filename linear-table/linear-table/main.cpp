#include "linear-table.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main() {
	cout << "linear practice." << endl;

	LinkList list = CREATE(10);
	LinkList p = nullptr;
	for (p = list; p != nullptr; p = p->link) {
		cout << p->data << ' ';
	}
	cout << endl;

	cout << LINKLEN(list) << endl;
	cout << ISEMPTY(list) << endl;
	system("pause");
	exit(0);
}