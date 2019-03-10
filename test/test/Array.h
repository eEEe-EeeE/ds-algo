#pragma once
#include <cassert>
template <class T>
class Array
{
private:
	T * list;
	int size;
public:
	Array();
	Array(const int & size);
	Array(const Array<T> & arr);
	Array<T> & operator = (const Array<T> & rhs);
	T & operator [] (const int & n);
	const T & operator [] (const int & n) const;
	operator T * ();
	operator T * () const;
	int getSize() const { return size; }
	void reSize(const int & n);
	~Array();
};
//模板函数定义
template <class T>
Array<T>::Array() :
	list(nullptr), size(0) {}

template <class T>
Array<T>::Array(const int & size)
{
	assert(size >= 0);
	list = new T[size];
	this->size = size;
}

template <class T>
Array<T>::~Array()
{
	delete[] list;
}

template <class T>
Array<T>::Array(const Array<T> & arr) {
	size = arr.getSize();
	list = new T[size];
	for (auto i = 0; i < arr.getSize(); ++i)
		list[i] = arr[i];
}

template <class T>
Array<T> & Array<T>::operator = (const Array<T> & arr) {
	if (this != &arr) {
		if (size != arr.getSize()) {
			delete[] list;
			size = arr.getSize();
			list = new T[size];
		}
		for (auto i = 0; i < arr.getSize(); ++i)
			list[i] = arr[i];
	}
	return *this;
}

template <class T>
T & Array<T>::operator [] (const int & n) {
	assert(size > 0 && 0 <= n && n <= size);
	return list[n];
}

template <class T>
const T & Array<T>::operator [] (const int & n) const {
	assert(size > 0 && 0 <= n && n <= size);
	return list[n];
}

template <class T>
Array<T>::operator T * () {
	return list;
}

template <class T>
Array<T>::operator T * () const {
	return list;
}

template <class T>
void Array<T>::reSize(const int & n) {
	assert(n >= 0);
	if (size == n)
		return;
	else {
		T * newList = new T[n];
		int sz = size < n ? size : n;
		for (auto i = 0; i < sz; ++i)
			newList[i] = list[i];
		delete[] list;
		size = n;
		list = newList;
		return;
	}
}