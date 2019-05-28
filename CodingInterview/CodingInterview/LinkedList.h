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

LinkedList* createList();
void dropList(LinkedList* list);
void insertNode(LinkedList* list, int data);
void deleteNode(LinkedList* list, int index);
#endif // !_LINKEDLIST_H
