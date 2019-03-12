#pragma once
#include <iostream>
#include <string>
#include "Node.h"
template <class T>
class LinkedList {
private:
	Node<T> *header, *footer;
	int size;

	Node<T> *prevPtr, *currPtr;
	int position;//����β�����

	Node<T> * newNode(const T & item, Node<T> * ptrNext = nullptr);
	void freeNode(Node<T> * ptr);
	void copy(const LinkedList<T> & list);
	void error(const std::string & msg) const {
		std::cout << msg << std::endl;
	}
public:
	LinkedList();
	LinkedList(const LinkedList & list);
	~LinkedList();

	LinkedList & operator = (const LinkedList & list);

	int getSize() const { return size; }
	bool isEmpty() const { return size ? true : false; }
	bool isHeader() const { return prevPtr == nullptr ? true : false; }
	bool isFooter() const { return currPtr == nullptr ? true : false; } //β��
	int getPosition() const { return position; }
	T & data() { return currPtr->data; }
	const T & data() const { return currPtr->data; }

	void next();
	void reset(const int & pos = 0);
	void clear();

	void insertHeader(const T & item);
	void insertFooter(const T & item);
	void insertBefore(const T & item);
	void insertAfter(const T & item);

	void deleteHeader();
	void deleteFooter();
	void deleteCurr();

};
//�½�һ�����
template <class T>
Node<T> * LinkedList<T>::newNode(const T & item, Node<T> * ptrNext) {
	Node<T> * newnode = new Node<T>;
	newnode->data = item;
	newnode->next = ptrNext;
	return newnode;
}
//�ͷ�һ�����
template <class T>
void LinkedList<T>::freeNode(Node<T> * ptr) {
	delete ptr;
}
//��������
template <class T>
void LinkedList<T>::copy(const LinkedList<T> & list) {
	if (list.isEmpty())
		return;
	clear();
	list.reset();
	while (!list.isFooter()) {
		Node<T> * newnode = newNode(list.data());
		if (list.isHeader()) {
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
//���캯��
template <class T>
LinkedList<T>::LinkedList() :
	header(nullptr), footer(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(-1) {}
//���ƹ��캯��
template <class T>
LinkedList<T>::LinkedList(const LinkedList & list) {
	copy(list);
}
//��������
template <class T>
LinkedList<T>::~LinkedList() {}
//���ظ�ֵ�����
template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & list) {
	if (this != &list) {
		clear();
		copy(list);
	}
	return *this;
}
//��ǰָ������ƶ�һ����λ
template <class T>
void LinkedList<T>::next() {
	if (prevPtr != footer) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
		++position;
	}
	else
		error("Out of range.");
}
//�����α�
template <class T>
void LinkedList<T>::reset(const int & pos) {
	if (0 <= pos && pos <= size) {
		if (!isEmpty()) {
			const int n = pos - position;
			if (n >= 0) {
				for (auto i = 0; i < n; ++i) {
					prevPtr = currPtr;
					currPtr = currPtr->next;
					++position;
				}
			}
			else {
				prevPtr = nullptr;
				currPtr = header;
				position = 0;
				for (auto i = 0; i < pos; ++i) {
					prevPtr = currPtr;
					currPtr = currPtr->next;
					++position;
				}
			}
		}
	}
}

//�������
template <class T>
void LinkedList<T>::clear() {
	Node<T> * nextNode;
	reset();
	while (!isFooter()) {
		nextNode = currPtr->next;
		freeNode(currPtr);
		currPtr = nextNode;
	}
	prevPtr = nullptr;
	position = -1;

	header = footer = nullptr;
	size = 0;
}

//��ͷ������
template <class T>
void LinkedList<T>::insertHeader(const T & item) {
	Node<T> * newnode = newNode(item, header);
	header = newnode;
	++size;
	if (isHeader())
		prevPtr = newnode;
	++position;
}

//��β������
template <class T>
void LinkedList<T>::insertAfter(const T & item) {
	Node<T> * newnode = newNode(item);
	footer->next = newnode;
	footer = newnode;
	++size;
	if (isFooter())
		prevPtr = newnode;
	++position;
}

//��ǰ���ǰ����һ�����
template <class T>
void LinkedList<T>::insertBefore(const T & item) {
	if (!isEmpty()) {
		if (!isHeader()) {
			Node<T> * newnode = newNode(item, currPtr);
			prevPtr->next = newnode;
			currPtr = newnode;
			++size;
		}
		else
			insertHeader(item);
	}
	else {
		Node<T> * newnode = newNode(item);
		currPtr = newnode;
		++position;
	}
}