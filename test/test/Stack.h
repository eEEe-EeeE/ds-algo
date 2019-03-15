#pragma once
#include <iostream>
#include <string>
//栈的用户维护边界条件
template <class T,int SIZE = 50>
class Stack {
private:
	T list[SIZE];
	int top;
	void error(const std::string & msg) {
		std::cout << msg << std::endl;
	}
public:
	Stack();
	bool isEmpty() const { return top == -1; }
	bool isFull() const { return top == SIZE - 1; }
	const T & peek() const;
	void push(const T & item);
	T pop();
	void clear();
};
template <class T, int SIZE>
Stack<T, SIZE>::Stack() :
	top(-1) {
}

template <class T, int SIZE>
 const T & Stack<T, SIZE>::peek() const {
	return list[top];
}

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T & item) {
	list[++top] = item;
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop() {
	return list[top--];
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear() {
	top = -1;
}