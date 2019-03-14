#pragma once
template <class T,int SIZE = 50>
class Stack {
private:
	T list[SIZE];
	int top;
public:
	bool isEmpty() { return top == -1 ? true : false; }
	bool isFull() { return top == SIZE - 1 ? true : false; }
	void push(const T & item);
	T pop();
	void clear();
};

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T & item) {
	
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop() {

}

template <class T, int SIZE>
void Stack<T, SIZE>::clear() {

}