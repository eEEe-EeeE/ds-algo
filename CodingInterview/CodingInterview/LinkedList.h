#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
typedef struct ListNode {
	int m_Key;
	ListNode* m_pNext;
} ListNode;

typedef struct {
	int listSize;
	ListNode* pHead;
} LinkedList;

void insertNode(LinkedList* list, int data);
void insertNode(int index, int data);
void deleteNode(int data);
void deleteNode(int index, int data);
#endif // !_LINKEDLIST_H
