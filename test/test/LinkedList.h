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
	bool isHeader() const { return prevPtr == nullptr ? true : false; } //������
	bool isEnd() const { return currPtr == nullptr ? true : false; } //β�󣬰�����
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
	Node<T> * new_node = new Node<T>;
	new_node->data = item;
	new_node->next = ptrNext;
	return new_node;
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
	while (!list.isEnd()) {
		Node<T> * new_node = newNode(list.data());
		if (list.isHeader()) {
			header = new_node;
		}
		else {
			currPtr->insertAfter(new_node);
		}
		prevPtr = currPtr;
		currPtr = new_node;
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
	while (!isEnd()) {
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
	reset();
	insertBefore(item);
}

//��β������
template <class T>
void LinkedList<T>::insertAfter(const T & item) {
	reset(size);
	insertBefore(item);
}

//��ǰ���ǰ����һ�����
template <class T>
void LinkedList<T>::insertBefore(const T & item) {
	Node<T> * new_node = newNode(item, currPtr);
	if (isHeader()) {
			header = new_node;
			if (isEmpty()) {
				footer = new_node;
				++position;
			}
		}
	else {
		if (isEnd())
			footer = new_node;
		prevPtr->next = new_node;
	}
	currPtr = new_node;
	++size;
}
//
template <class T>
void LinkedList<T>::insertFooter(const T & item) {
	Node<T> * new_node = newNode(item, currPtr->next);
	if (!isEmpty()) {
		if (isEnd()) {
			error("Out of range.");
			return;
		}
		if (currPtr->next == nullptr)
			footer = new_node;
		currPtr->next = new_node;
	}
	else {
		header = footer = new_node;
	}
	prevPtr = currPtr;
	currPtr = new_node;
	++position;
	++size;
}
//
template <class T>
void LinkedList<T>::deleteHeader() {
	reset();
	deleteCurr();
}
//
template <class T>
void LinkedList<T>::deleteFooter() {
	reset(size - 1);
	deleteCurr();
}
//
template <class T>
void LinkedList<T>::deleteCurr() {
	if (!isEmpty()) {
		if (!isHeader()) {
			Node<T> * old_node;
			old_node = prevPtr->deleteAfter();
		}
	}
}