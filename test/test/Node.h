#pragma once

template <class T>
class Node {
private:
	Node<T> * next;
public:
	T data;
	Node(const T & data, Node<T> * next = 0);
	void insertAfter(Node<T> *newNode);
	Node<T> * deleteAfter();
	Node<T> * nextNode();
	const Node<T> * nextNode() const;
};
//���캯��
template <class T>
Node<T>::Node(const T & data, Node<T> * next) :
	data(data), next(next) {}
//�ڵ�ǰ���֮�����һ�����
template <class T>
void Node<T>::insertAfter(Node<T> * newNode) {
	newNode->next = next;
	next = newNode;
}
//�ڵ�ǰ���֮��ɾ��һ�����
template <class T>
Node<T> * Node<T>::deleteAfter() {
	Node<T> * old_Node = next;
	next = next->next;
	return old_Node;
}
//��ǰ������һ�����
template <class T>
Node<T> * Node<T>::nextNode() {
	return next;
}
//��ǰ������һ�����
template <class T>
const Node<T> * Node<T>::nextNode() const {
	return next;
}