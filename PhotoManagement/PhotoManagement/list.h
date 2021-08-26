#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstring>

#define MAXSIZE 100

/*
*	empty list class for class List
*/
class EmptyList : public std::exception {
private:
	std::string message;
public:
	EmptyList(std::string str = "") : message("List is empty.") { }
	virtual const char* what() {
		return message.c_str();
	}
};

/*
*	full list class for class List
*/
class FullList : public std::exception {
private:
	std::string message;
public:
	FullList(std::string str = "") : message("List is full.") { }
	virtual const char* what() {
		return message.c_str();
	}
};

/*
*	Itemcheking class for class List
*/
class ItemNotFound : public std::exception {
private:
	std::string message;
public:
	ItemNotFound(std::string str = "") : message("Key not found in the "+str) { }
	virtual const char* what() {
		return message.c_str();
	}
};

/*
*	���� �Ҵ��� �̿��Ͽ� ����Ʈ Ŭ������ ����
*/
template <class T>
class List {
private:
	T* m_Array; // �����Ҵ� �迭
	int curIndx; // ���� ��ġ Ŀ��
	int m_Length; // �迭 ����
	int maxSize; // �迭 �ִ� ������
public:
	/*
	*	@brief	constructor.
	*/
	List(int size = MAXSIZE);

	/*
	*	@brief	destructor.
	*/
	~List();



	/*
	*	@brief	�迭�� ���Ұ� ���� ���ִ��� Ȯ��
	*	@pre	�迭 ���̿� �迭 �ִ� ����� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	�迭�� ���̸� �ִ� ������� ��
	*/
	bool IsFull() const { return m_Length >= maxSize-1 ? true : false; }

	/*
	*	@brief	�迭�� ���Ұ� ����ִ��� Ȯ��
	*	@pre	�迭 ���̰� ���� ���־�� ��
	*	@post	none
	*	@param	none
	*	@return	�迭�� ���̰� 0���� ��
	*/
	bool IsEmpty() const { return m_Length == 0 ? true : false; }

	/*
	*	@brief	�迭�� ���̸� Ȯ��
	*	@pre	�迭 ���̰� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	�迭�� ���̸� ��ȯ
	*/
	int GetLength() const { return m_Length; }

	/*
	*	@brief	�迭�� ��� ���� ����
	*	@pre	none
	*	@post	�迭�� ���̸� 0���� ����
	*	@param	none
	*	@return	none
	*/
	void MakeEmpty() { m_Length = 0; }

	/*
	*	@brief	�����͸� �迭�� �߰�
	*	@pre	�迭�� �����Ҵ� �Ǿ��־�� ��
	*	@post	�迭�� ���Ҹ� �߰�
	*	@param	�߰��� �ش� Ÿ���� ������
	*	@return	�߰��� �����ϸ� true ��ȯ
	*/
	bool PutItem(T& item);

	/*
	*	@brief	�����͸� �迭���� ����
	*	@pre	�迭�� �����Ҵ� �Ǿ��־�� ��
	*	@post	�迭���� ���Ҹ� ����
	*	@param	������ �ش� Ÿ���� ������
	*	@return	������ �����ϸ� true ��ȯ
	*/
	bool DeleteItem(T& item);

	/*
	*	@brief	Ŀ���� �ʱ�ȭ
	*	@pre	none
	*	@post	Ŀ���� -1�� ����
	*	@param	none
	*	@return	none
	*/
	void ResetList() { curIndx = -1; }

	/*
	*	@brief	Ŀ���� �������� ���� ���Ҹ� ��ȯ
	*	@pre	�迭�� ���Ұ� �־�� ��
	*	@post	Ŀ���� +1��
	*	@param	��ȯ�� ������
	*	@return	���� ���Ҹ� �� ��ȯ�Ͽ��ٸ� true��ȯ
	*/
	bool GetNextItem(T& item);

	/*
	*	@brief	Ŀ���� �������� ���� ������ �ּҰ� ��ȯ
	*	@pre	�迭�� ���Ұ� �־�� ��
	*	@post	Ŀ���� +1��
	*	@param	none
	*	@return	���� ������ �ּҰ� ��ȯ
	*/
	T* GetNextItemPtr();

	/*
	*	@brief	����Ž������ ������ Ž��
	*	@pre	�迭�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	ã���� �ϴ� ���� ������
	*	@return	ã�Ҵٸ� �ش� ���� �ε��� ��ȯ, �׷��� �ʴٸ� -1��ȯ
	*/
	int Retrieve(T& item);

	/*
	*	@brief	����Ž������ ������ Ž��
	*	@pre	�迭�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	ã���� �ϴ� ���� ������
	*	@return	ã�Ҵٸ� �ش� ���� �ּҰ� ��ȯ, �׷��� �ʴٸ� NULL��ȯ
	*/
	T* RetrievePtr(T& itme);
};

// constructor
template <class T>
List<T>::List(int size) {
	m_Length = 0;
	maxSize = size;
	m_Array = new T[maxSize];
	curIndx = -1;
}

// destructor
template <class T>
List<T>::~List() {
	MakeEmpty();
	if (maxSize > 0) // �����Ҵ� �迭 ����
		delete[] m_Array;
}

// �����͸� �迭�� �߰�
template <class T>
bool List<T>::PutItem(T& item) {
	// �迭�� ���� ���ִ��� Ȯ��
	if (IsFull()) {
		FullList e;
		throw e;
	}
	try {
		// ����ִ� ���¿��� �߰�
		if (m_Length == 0) {
			m_Array[m_Length++] = item;
			return true;
		}
		else {
			// ������ ���� ���������� ���������� Ȯ��
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
		std::cout << e.what() << std::endl;
		return false;
	}
}

// �����͸� �迭���� ����
template <class T>
bool List<T>::DeleteItem(T& item) {
	// �迭�� ����ִ��� Ȯ��
	if (IsEmpty()) {
		EmptyList e;
		throw e;
	}
	try {
		int idx = Retrieve(item); // ������ �迭 ���� ��ġ Ȯ��
		if (idx == -1) {
			ItemNotFound e("List");
			throw e;
		}
		// ����
		for (int i = idx; i < m_Length; ++i)
			m_Array[i] = m_Array[i+1];
		m_Length--;
		return true;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
}

// Ŀ���� �������� ���� ���Ҹ� ��ȯ
template <class T>
bool List<T>::GetNextItem(T& item) {
	curIndx++;
	// �迭 ������ Ȯ���ϰ� ��ȯ
	if (curIndx < m_Length) {
		item = m_Array[curIndx];
		return true;
	}
	else
		return false;
}

// Ŀ���� �������� ���� ������ �ּҰ� ��ȯ
template <class T>
T* List<T>::GetNextItemPtr() {
	curIndx++;
	// �迭 ������ Ȯ���ϰ� ��ȯ
	if (curIndx < m_Length)
		return &m_Array[curIndx];
	else
		return nullptr;
}

// ����Ž������ ������ Ž��
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
			return mid; // �ش� ������ �ε��� ��ȯ
		}
	}
	return -1;
}

// ����Ž������ ������ Ž��
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
			return &m_Array[mid]; // �ش� ������ �ּҰ� ��ȯ
		}
	}
	return nullptr;
}