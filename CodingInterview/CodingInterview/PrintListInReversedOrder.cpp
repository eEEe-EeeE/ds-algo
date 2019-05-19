#include "ListNode.h"
#include <iostream>
#include <stack>

void printListInReversedOrder(ListNode* pHead) {
	ListNode* pCount = pHead;
	std::stack<int> sp;
	while (pCount != nullptr) {
		sp.push(pCount->m_Key);
		pCount = pCount->m_pNext;
	}

	while (!sp.empty()) {
		std::cout << sp.top() << ' ';
		sp.pop();
	}
}