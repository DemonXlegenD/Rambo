#pragma once

/*==============================================================================================================================================*/
/*-----------------------------------------------------------------CONSTRUCTORS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

template<typename T>
Vector<T>::Vector() : size(0), capacity(1), dynamicArray(new T[1]) {}

template<typename T>
Vector<T>::Vector(int size, int capacity, T& dynamicArray) : size(size), capacity(capacity), dynamicArray(dynamicArray) {}


/*==============================================================================================================================================*/
/*-----------------------------------------------------------------OPERATORS--------------------------------------------------------------------*/
/*==============================================================================================================================================*/

//OPERATOR =

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& otherVector) {
	if (this != &otherVector) {
		delete[] dynamicArray;
		size = otherVector.getSize();
		capacity = otherVector.getCapacity();
		if (capacity > 0) {
			dynamicArray = new T[capacity];
			std::copy(otherVector.getArray(), otherVector.getArray() + size, dynamicArray);
		}
		else {
			dynamicArray = nullptr;
		}
	}

	return *this;
}

//OPERATOR ==

template<typename T>
//template <typename U = T, std::enable_if_t<decltype(std::declval<T>() == std::declval<T>())>> : std::true_type{}; >
bool Vector<T>::operator==(const Vector<T>& otherVector) const {
	if (size == otherVector.getSize()) {
		for (int i = 0; i < size; i++) {
			if (dynamicArray[i] != otherVector.at(i)) return false;
		}
	}
	else {
		return false;
	}
	return true;
}

//OPERATOR !=

template<typename T>
//template <typename U = T, std::enable_if_t<decltype(std::declval<T>() == std::declval<T>())>> : std::true_type{}; >
bool Vector<T>::operator!=(const Vector<T>& otherVector) const {
	if (size == otherVector.getSize()) {
		for (int i = 0; i < size; i++) {
			if (dynamicArray[i] == otherVector.at(i)) return false;
		}
	}
	return true;
}

/*==============================================================================================================================================*/
/*--------------------------------------------------------------------HOME MADE-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

//GET ARRAY

template<typename T>
T* Vector<T>::getArray() const {
	return dynamicArray;
}

//SET ARRAY

template<typename T>
void Vector<T>::setArray(T& array, int newSize) {
	delete[] dynamicArray;

	// Copiez le tableau et sa taille
	dynamicArray = new int[newSize];
	size = newSize;
	for (int i = 0; i < newSize; ++i) {
		dynamicArray[i] = array[i];
	}
}

//GET ELEMENT BY INDEX

template<typename T>
T Vector<T>::getElementByIndex(const int index) const {
	if (index >= 0 && index < size) {
		return dynamicArray[index];
	}
	Error::RaiseOutOfRangeError(std::string("Index out of range"));
	return NULL;
}

//SHOW ELEMENTS

template<typename T>
void Vector<T>::showElements() {
	for (int i = 0; i < size; i++) {
		std::cout << i << "." << dynamicArray[i] << std::endl;
	}
}

//FIND INDEX BY ELEMENT

template<typename T>
int Vector<T>::findIndexByElement(T& findElement) {
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] == findElement) return i;
	}
	GameLog::error(std::string("No element : " + findElement));
	return -1;
}

/*==============================================================================================================================================*/
/*--------------------------------------------------------------------ITERATORS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/


//BEGIN

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
	return Iterator(dynamicArray);
}

//END

template<typename T>
typename Vector<T>::Iterator Vector<T>::end() {
	return Iterator(dynamicArray + size);
}

//RBEGIN

template<typename T>
typename Vector<T>::Iterator Vector<T>::rbegin() {
	return Iterator(dynamicArray + size - 1);
}

//REND

template<typename T>
typename Vector<T>::Iterator Vector<T>::rend() {
	T* array = dynamicArray;
	return Iterator(dynamicArray - 1);
}

//CBEGIN

template<typename T>
typename Vector<T>::Iterator Vector<T>::cbegin() const {
	return Iterator(dynamicArray);
}

//CEND

template<typename T>
typename Vector<T>::Iterator Vector<T>::cend() const {
	return Iterator(dynamicArray + size);
}

//CRBEGIN

template<typename T>
typename Vector<T>::Iterator Vector<T>::crbegin() const {
	const T* array = dynamicArray;
	return Iterator(dynamicArray + size - 1);
}

//CREND

template<typename T>
typename Vector<T>::Iterator Vector<T>::crend() const {
	return Iterator(dynamicArray - 1);
}

/*==============================================================================================================================================*/
/*-------------------------------------------------------------------CAPACITY-------------------------------------------------------------------*/
/*==============================================================================================================================================*/


//GET SIZE

template<typename T>
int Vector<T>::getSize() const {
	return size;
}

//GET CAPACITY

template<typename T>
int Vector<T>::getCapacity() const {
	return capacity;
}

//GET LEFT CAPACITY

template<typename T>
int Vector<T>::getLeftCapacity() const {
	return capacity - size;
}

//RESIZES

template<typename T>
void Vector<T>::resize(int newSize) {
	if (newSize > capacity) {
		reserve(newSize);
	}
	if (newSize > size) {
		for (int i = size; i < newSize; i++) {
			dynamicArray[i] = 0;
		}
	}
	else {
		T* newArray = new T[capacity];
		for (int i = 0; i < newSize; i++) {
			newArray[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}

}

template<typename T>
void Vector<T>::resize(int newSize, T& element) {
	if (newSize > capacity) {
		reserve(newSize);
	}
	if (newSize > size) {
		for (int i = size; i < newSize; i++) {
			dynamicArray[i] = element;
		}
	}
	else {
		T* newArray = new T[capacity];
		for (int i = 0; i < newSize; i++) {
			newArray[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}


//EMPTY

template<typename T>
bool Vector<T>::empty() {
	return size == 0;
}

//RESERVE

template<typename T>
void Vector<T>::reserve(int newCapacity) {
	if (newCapacity > capacity) {
		capacity = newCapacity;
		T* newArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			newArray[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

//SHRINK TO FIT

template<typename T>
void Vector<T>::shrinkToFit() {
	if (size > 0) {
		capacity = size;
		resize(capacity);
	}
}


/*==============================================================================================================================================*/
/*----------------------------------------------------------------ELEMENT ACCESS----------------------------------------------------------------*/
/*==============================================================================================================================================*/


//OPERATOR []
template<typename T>
T Vector<T>::operator[](int index) {
	return *(dynamicArray + index);
}

//AT

template<typename T>
T Vector<T>::at(int index) const {
	return dynamicArray[index];
}

//FRONT

template<typename T>
T Vector<T>::front() const {
	return *(dynamicArray);
}

//BACK
template<typename T>
T Vector<T>::back() const {
	return *(dynamicArray + size);
}

//DATA

template<typename T>
T Vector<T>::data() {
	T* dataPointer = dynamicArray;
	return dataPointer;
}


/*==============================================================================================================================================*/
/*--------------------------------------------------------------------MODIFIERS-----------------------------------------------------------------*/
/*==============================================================================================================================================*/


//ASSIGNS

/*
*/
template<typename T>
void Vector<T>::assign(int size, T& value) {
	if (size != 0) {
		empty();
	}
	resize(size, T);
}

template<typename T>
void Vector<T>::assign(Vector& Vector) {
	size = Vector.getSize();
	capacity = Vector.getCapacity();
	delete[] dynamicArray;
	dynamicArray = Vector.getAllElements();
}

template<typename T>
void Vector<T>::assign(Iterator& first, Iterator& last) {
	int newSize = 0;
	for (Iterator it = first; it != last; ++it) {
		++newSize;
	}
	if (newSize > capacity) {
		reserve(newSize);
	}
	size = 0;
	for (Iterator it = first; it != last; ++it) {
		dynamicArray[size] = *it;
		++size;
	}
}

//PUSH BACK

template<typename T>
void Vector<T>::push_back(T& element) {
	if (size >= capacity) {
		reserve(capacity * 2);
	}
	dynamicArray[size] = element;
	size++;
}

//POP BACK

template<typename T>
void Vector<T>::pop_back() {
	if (size > 0) {
		size--;
		if (size < capacity / 2) {
			capacity /= 2;
		}
		reserve(capacity);
	}
}

//INSERTS

template<typename T>
void Vector<T>::insert(int position, T& value) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		size++;
		int index = 0;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				newArray[i] = value;
				index++;
			}
			else {
				newArray[i] = dynamicArray[i - index];
			}

		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

template<typename T>
void Vector<T>::insert(int position, T& value, int number) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		size += number;
		int index = 0;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				newArray[i] = value;
				index++;
			}
			else {
				newArray[i] = dynamicArray[i - index];
			}
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

template<typename T>
void Vector<T>::insert(int position, Vector& Vector) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		size += Vector.getSize();
		int index = 0;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				newArray[i] = Vector.at(index);
				index++;
			}
			else {
				newArray[i] = dynamicArray[i - index];
			}
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

template<typename T>
void Vector<T>::insert(int position, Iterator& first, Iterator& last) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		int numElementsToInsert = 0;
		for (Iterator it = first; it != last; ++it) {
			++numElementsToInsert;
		}

		if (size + numElementsToInsert > capacity) {
			reserve(size + numElementsToInsert);
		}

		for (Iterator it = end(); it != position; --it) {
			*(dynamicArray + numElementsToInsert) = *it;
		}
		int index = 0;
		for (Iterator it = first; it != last; ++it) {
			*(dynamicArray + index) = *it;
			index++;
			++size;
		}
	}
}

//CLEAR

template<typename T>
void Vector<T>::clear() {
	size = 0;
	delete[] dynamicArray;
	dynamicArray = new T[capacity];
}

//ERASES

template<typename T>
void Vector<T>::erase(int position) {
	if (position >= size) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		int index = 0;
		size--;
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == position) {
				index++;
			}
			newArray[i] = dynamicArray[i + index];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

template<typename T>
void Vector<T>::erase(int from, int to) {
	if (from >= size || to >= size || from < to) {
		Error::RaiseOutOfRangeError(std::string("Position out of range"));
	}
	else {
		int index = 0;
		size -= (to - from + 1);
		T* newArray = new T[size];
		for (int i = 0; i < size; i++) {
			if (i >= from && i <= to) {
				index = (to - from + 1);
			}
			newArray[i] = dynamicArray[i + index];
		}
		delete[] dynamicArray;
		dynamicArray = newArray;
	}
}

//SWAP

template<typename T>
void Vector<T>::swap(Vector& otherVector) {
	/*Temporaire*/
	int tempSize = otherVector.getSize();
	int tempCapacity = otherVector.getCapacity();
	T* tempArray = otherVector.getArray();

	/*Modify otherVector*/
	otherVector.setArray(dynamicArray);
	otherVector.reserve(capacity);
	otherVector.resize(size);

	/*Modify actualVector*/
	dynamicArray = tempArray;
	size = tempSize;
	capacity = tempCapacity;
}

//EMPLACES

template<typename T>
typename Vector<T>::Iterator Vector<T>::emplace(Iterator& iterator, T& value) {
	size++;
	if (size > capacity) {
		reserve(size);
	}
	for (Iterator it = end(); it != iterator; --it) {
		*(dynamicArray + 1) = *it;
	}
	*(dynamicArray + iterator) = *iterator;

	return iterator;
}

template<typename T>
void Vector<T>::emplace_back(T& value) {
	size++;
	if (size > capacity) {
		reserve(size);
	}
	Iterator end = end();
	*(dynamicArray + end) = *end;
}


/*==============================================================================================================================================*/
/*-------------------------------------------------------------------DESTRUCTOR-----------------------------------------------------------------*/
/*==============================================================================================================================================*/

//DESTRUCTOR

template<typename T>
Vector<T>::~Vector() {
	delete[] dynamicArray;
}