#include "LinkedList.h"
#include <iostream>
#include <stack>


void printListInReversedOrder(LinkedList* list) {
	ListNode* p = list->pHead;
	std::stack<int> sp;
	while (p != nullptr) {
		sp.push(p->m_Key);
		p = p->m_pNext;
	}

	while (!sp.empty()) {
		std::cout << sp.top() << ' ';
		sp.pop();
	}
}