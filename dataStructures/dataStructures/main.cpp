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
	PRINTLIST(list);

	cout << "linklist length: " << LINKLEN(list) << endl;
	cout << "is empty?: " << ISEMPTY(list) << endl;

	INSERTLINK1(&list, 22);
	INSERTLINK2(list, 11);
	INSERTLINK3(&list, list->link, 44);
	PRINTLIST(list);



	system("pause");
	exit(0);
}