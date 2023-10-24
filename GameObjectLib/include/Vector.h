#pragma once
#include <iostream>
#include "../Game/include/Game/GameLog.h"
#include "../Game/include/Error.h"
#include <type_traits>

template<typename T>
class Vector
{
public:
	/*CONSTRUCTOR*/

	Vector();
	Vector(int size, int capacity, T& dynamicArray);

	/*OPERATOR*/

	Vector<T>& operator=(const Vector& otherVector);
	bool operator==(const Vector& otherVector) const;
	bool operator!=(const Vector& otherVector) const;

	/*HOME MADE*/

	T* getArray() const;
	void setArray(T& array, int newSize);
	T getElementByIndex(const int index) const;
	void showElements();
	int findIndexByElement(T& element);

	/*ITERATORS*/

	class Iterator {
	private:
		T* ptr;

	public:
		Iterator(T* p) : ptr(p) {}

		T& operator*() {
			return *ptr;
		}

		Iterator& operator++() {
			++ptr;
			return *this;
		}

		Iterator& operator--() {
			--ptr;
			return *this;
		}

		bool operator==(const Iterator& other) const {
			return ptr == other.ptr;
		}

		bool operator!=(const Iterator& other) const {
			return ptr != other.ptr;
		}
	};

	Iterator begin();
	Iterator end();
	Iterator rbegin();
	Iterator rend();
	Iterator cbegin() const;
	Iterator cend() const;
	Iterator crbegin() const;
	Iterator crend() const;

	/*CAPACITY*/
	int getSize() const;
	int getCapacity() const;
	int getLeftCapacity() const;
	void resize(int size);
	void resize(int newSize, T& element);
	bool empty();
	void reserve(int capacity);
	void shrinkToFit();

	/*ELEMENT ACCESS*/
	T operator[](int index);
	T at(int index) const;
	T front() const;
	T back() const;
	T data();

	/*MODIFIERS*/
	void assign(int size, T& value);
	void assign(Vector& vector);
	void assign(Iterator& first, Iterator& last);

	void push_back(T& element);
	void pop_back();

	void insert(int position, T& value);
	void insert(int position, T& value, int number);
	void insert(int position, Vector& vector);
	void insert(int position, Iterator& first, Iterator& last);

	void erase(int position);
	void erase(int from, int to);

	void swap(Vector& otherVector);

	void clear();

	Iterator emplace(Iterator& it, T& value);
	void emplace_back(T& value);

	/*DESTRUCTOR*/
	~Vector();

private:
	int size = 0;
	int capacity = 1;
	T* dynamicArray = new T[capacity];
};

#include "Vector.inl"