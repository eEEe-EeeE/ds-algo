#pragma once
#include <iostream>
#include <string>
template <class T,int SIZE = 50>
class Stack {
private:
	T list[SIZE];
	int top;
	void error(const std::string & msg) {
		std::cout << msg << std::endl;
	}
public:
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == SIZE - 1; }
	const T & peek() const;
	void push(const T & item);
	T pop();
	void clear();
};

template <class T, int SIZE>
const T & Stack<T, SIZE>::peek() const {
	if (!isEmpty()) {
		return list[top];
	}
}

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T & item) {
	if (!isFull()) {
		list[++top] = item;
	}
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop() {
	if (!isEmpty()) {
		return list[top--];
	}
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear() {
	top = -1;
}