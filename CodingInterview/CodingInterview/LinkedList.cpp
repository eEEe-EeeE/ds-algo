#include "LinkedList.h"
#include <cstdlib>

LinkedList* createList() {
	LinkedList* p = (LinkedList*)malloc(sizeof(LinkedList));
	if (p != nullptr) {
		p->listSize = 0;
		p->pHead = nullptr;
	}
	return p;
}

void insertNode(LinkedList* list, int data) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp != nullptr) {
		temp->m_Key = data;
		temp->m_pNext = nullptr;
	}
	else
		return;

	if (list->pHead == nullptr) {
		list->pHead = temp;
		list->listSize = 1;
	}
	else {
		temp->m_pNext = list->pHead;
		list->pHead = temp;
		list->listSize += 1;
	}
}

void deleteNode(LinkedList* list, int index) {
	if (list->listSize == 0 || index > list->listSize)
		return;

	ListNode* p = nullptr;
	if (index == 1) {
		p = list->pHead;
		list->pHead = list->pHead->m_pNext;
		free(p);
	}
	else {
		int i = 1;
		ListNode* pre = list->pHead;
		while (++i != index) {
			pre = pre->m_pNext;
		}
		p = pre->m_pNext;
		pre->m_pNext = pre->m_pNext->m_pNext;
		free(p);
	}

}

void dropList(LinkedList* list) {
	ListNode* p = list->pHead;
	ListNode* temp = nullptr;
	while (p != nullptr) {
		temp = p;
		p = p->m_pNext;
		free(temp);
	}
	free(list);
}