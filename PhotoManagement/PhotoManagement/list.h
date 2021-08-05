#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstring>

#define MAXSIZE 100

class EmptyList : public std::exception {
private:
	std::string message;
public:
	EmptyList(std::string str = "") : message("List is empty.") { }
	virtual const char* what() {
		return message.c_str();
	}
};

class FullList : public std::exception {
private:
	std::string message;
public:
	FullList(std::string str = "") : message("List is full.") { }
	virtual const char* what() {
		return message.c_str();
	}
};

class ItemNotFound : public std::exception {
private:
	std::string message;
public:
	ItemNotFound(std::string str = "") : message("Key not found in the "+str) { }
	virtual const char* what() {
		return message.c_str();
	}
};

template <class T>
class List {
private:
	T* m_Array;
	int curIndx;
	int m_Length;
	int maxSize;
public:
	List(int size = MAXSIZE);
	~List();
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	void MakeEmpty();
	bool PutItem(T item);
	bool DeleteItem(T item);
	void ResetList();
	bool GetNextItem(T& item);
	T* GetNextItemPtr();
	int Retrieve(T& item);
	T* RetrievePtr(T& itme);

};

template <class T>
List<T>::List(int size) {
	m_Length = 0;
	maxSize = size;
	m_Array = new T[maxSize];
}

template <class T>
List<T>::~List() {
	MakeEmpty();
	if (maxSize > 0)
		delete[] m_Array;
}

template <class T>
bool List<T>::IsFull() const {
	if (m_Length >= maxSize-1)
		return true;
	else
		return false;
}

template <class T>
bool List<T>::IsEmpty() const {
	if (m_Length == 0)
		return true;
	else
		return false;
}

template <class T>
int List<T>::GetLength() const {
	return m_Length;
}

template <class T>
void List<T>::MakeEmpty() {
	m_Length = 0;
}

template <class T>
bool List<T>::PutItem(T item) {
	if (IsFull()) {
		FullList e;
		throw e;
	}
	try {
		if (m_Length == 0) {
			m_Array[m_Length++] = item;
			return true;
		}
		else {
			for (int i = m_Length - 1; i >= 0; --i) {
				if (item > m_Array[i]) {
					m_Array[i + 1] = item;
					return true;
				}
				m_Array[i + 1] = m_Array[i];
			}
			m_Array[0] = item;
			m_Length++;
			return true;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << endl;
		return false;
	}
}

template <class T>
bool List<T>::DeleteItem(T item) {
	if (IsEmpty()) {
		EmptyList e;
		throw e;
	}
	try {
		int idx = Retrieve(item);
		if (idx == -1) {
			ItemNotFound e("List");
			throw e;
		}
		for (int i = idx; i < m_Length; ++i)
			m_Array[i] = m_Array[i+1];
		m_Length--;
		return true;
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

template <class T>
void List<T>::ResetList() {
	curIndx = -1;
}

template <class T>
bool List<T>::GetNextItem(T& item) {
	curIndx++;
	if (curIndx < m_Length) {
		item = m_Array[curIndx];
		return true;
	}
	else
		return false;
}

template <class T>
T* List<T>::GetNextItemPtr() {
	curIndx++;
	if (curIndx < m_Length)
		return &m_Array[curIndx];
	else
		return nullptr;
}

template <class T>
int List<T>::Retrieve(T& item) {
	int start = 0, end = m_Length-1;
	while (start <= end) {
		int mid = (start+end)/2;
		if (item > m_Array[mid])
			start = mid+1;
		else if (item < m_Array[mid])
			end = mid-1;
		else {
			item = m_Array[mid];
			return mid;
		}
	}
	return -1;
}

template <class T>
T* List<T>::RetrievePtr(T& item) {
	int start = 0, end = m_Length - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (item > m_Array[mid])
			start = mid + 1;
		else if (item < m_Array[mid])
			end = mid - 1;
		else {
			item = m_Array[mid];
			return &m_Array[mid];
		}
	}
	return nullptr;
}