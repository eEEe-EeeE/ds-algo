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
//构造函数
template <class T>
Node<T>::Node(const T & data, Node<T> * next) :
	data(data), nextPtr(next) {}
//在当前结点之后插入一个结点
template <class T>
void Node<T>::insertAfter(Node<T> * newNode) {
	if (newNode != nullptr) {
		newNode->nextPtr = nextPtr;
		nextPtr = newNode;
	}
}
//在当前结点之后删除一个结点
template <class T>
Node<T> * Node<T>::deleteAfter() {
	Node<T> * old_Node = nextPtr;
	nextPtr = nextPtr->nextPtr;
	return old_Node;
}
//当前结点的下一个结点
template <class T>
Node<T> * Node<T>::nextNode() {
	return nextPtr;
}
//当前结点的下一个结点
template <class T>
const Node<T> * Node<T>::nextNode() const {
	return nextPtr;
}