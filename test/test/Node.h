#pragma once

template <class T>
class Node {
private:
	Node<T> * next;
public:
	T data;
	Node(const T & data, Node<T> * next = 0);
	void insertAfter(const T & item);
	Node<T> * deleteAfter();
	Node<T> * nextNode();
	const Node<T> * nextNode() const;
};

template <class T>
Node<T>::Node(const T & data, Node<T> * next) :
	data(data), next(next) {}

template <class T>
void Node<T>::insertAfter(const T & item) {
	Node<T> * newNode = new Node<T>;
	newNode->next = next;
	newNode->data = item;
	next = newNode;
}

template <class T>
Node<T> * Node<T>::deleteAfter() {
	Node<T> * oldNode = next;
	next = next->next;
	return oldNode;
}

template <class T>
Node<T> * Node<T>::nextNode() {
	return next;
}

template <class T>
const Node<T> * Node<T>::nextNode() const {
	return next;
}