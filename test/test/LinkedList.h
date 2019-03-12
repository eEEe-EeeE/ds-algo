#pragma once
#include "Node.h"
template <class T>
class LinkedList {
private:
	Node<T> *header, *footer;
	Node<T> *prevPtr, *currPtr;
	int size;
	int position;

	Node<T> * newNode(const T & item, Node<T> * ptrNext = nullptr);
	void freeNode(Node<T> * ptr);
	void copy(const LinkedList<T> & list);
public:
	LinkedList();
	LinkedList(const LinkedList & list);
	~LinkedList();

	LinkedList & operator = (const LinkedList & list);

	int getSize() const { return size; }
	bool isEmpty() const { return size ? true : false; }
	bool isFooter() const { return position == size - 1 ? true : false; }
	int getPosition() const { return position; }
	T & data() { return currPtr->data; }
	const T & data() const { return currPtr->data; }

	void next();
	void reset(int pos = 0);
	void clear();

	void insertHeader(const T & item);
	void insertFooter(const T & item);
	void insertBefore(const T & item);
	void insertAfter(const T & item);

	void deleteHeader();
	void deleteFooter();
	void deleteCurr();

};
//新建一个结点
template <class T>
Node<T> * LinkedList<T>::newNode(const T & item, Node<T> * ptrNext) {
	Node<T> * newnode = new Node<T>;
	newnode->data = item;
	newnode->next = ptrNext;
	return newnode;
}
//释放一个结点
template <class T>
void LinkedList<T>::freeNode(Node<T> * ptr) {
	delete ptr;
}
//复制链表
template <class T>
void LinkedList<T>::copy(const LinkedList<T> & list) {
	if (list.isEmpty())
		return;
	clear();
	list.reset();
	while (list.getPosition() != list.getSize()) {
		Node<T> * newnode = newNode(list.data());
		if (list.getPosition() == 0) {
			header = newnode;
		}
		else {
			currPtr->insertAfter(newnode);
		}
		prevPtr = currPtr;
		currPtr = newnode;
		++size;
		++position;
		list.next();
	}
	footer = currPtr;
	list.reset();
	reset();
}
//构造函数
template <class T>
LinkedList<T>::LinkedList() :
	header(nullptr), footer(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(-1) {}
//复制构造函数
template <class T>
LinkedList<T>::LinkedList(const LinkedList & list) {
	copy(list);
}
//析构函数
template <class T>
LinkedList<T>::~LinkedList() {}
//重载赋值运算符
template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & list) {
	if (this != &list) {

	}
}