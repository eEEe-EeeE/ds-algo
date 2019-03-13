#pragma once

template <class T>
class Node {
private:
	Node<T> * nextPtr;
public:
	T data;
	Node(const T & data, Node<T> * next = nullptr);
	void insertAfter(Node<T> *newNode);
	Node<T> * deleteAfter();
	Node<T> * nextNode();
	const Node<T> * nextNode() const;
};
//���캯��
template <class T>
Node<T>::Node(const T & data, Node<T> * next) :
	data(data), nextPtr(next) {}
//�ڵ�ǰ���֮�����һ�����
template <class T>
void Node<T>::insertAfter(Node<T> * newNode) {
	if (newNode != nullptr) {
		newNode->nextPtr = nextPtr;
		nextPtr = newNode;
	}
}
//�ڵ�ǰ���֮��ɾ��һ�����
template <class T>
Node<T> * Node<T>::deleteAfter() {
	Node<T> * old_Node = nextPtr;
	nextPtr = nextPtr->nextPtr;
	return old_Node;
}
//��ǰ������һ�����
template <class T>
Node<T> * Node<T>::nextNode() {
	return nextPtr;
}
//��ǰ������һ�����
template <class T>
const Node<T> * Node<T>::nextNode() const {
	return nextPtr;
}