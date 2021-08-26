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
*	동적 할당을 이용하여 리스트 클래스를 구현
*/
template <class T>
class List {
private:
	T* m_Array; // 동적할당 배열
	int curIndx; // 현재 위치 커서
	int m_Length; // 배열 길이
	int maxSize; // 배열 최대 사이즈
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
	*	@brief	배열에 원소가 가득 차있는지 확인
	*	@pre	배열 길이와 배열 최대 사이즈가 초기화 되어 있어야 함
	*	@post	none
	*	@param	none
	*	@return	배열의 길이를 최대 사이즈와 비교
	*/
	bool IsFull() const { return m_Length >= maxSize-1 ? true : false; }

	/*
	*	@brief	배열에 원소가 비어있는지 확인
	*	@pre	배열 길이가 설정 되있어야 함
	*	@post	none
	*	@param	none
	*	@return	배열의 길이가 0인지 비교
	*/
	bool IsEmpty() const { return m_Length == 0 ? true : false; }

	/*
	*	@brief	배열의 길이를 확인
	*	@pre	배열 길이가 초기화 되어 있어야 함
	*	@post	none
	*	@param	none
	*	@return	배열의 길이를 반환
	*/
	int GetLength() const { return m_Length; }

	/*
	*	@brief	배열의 모든 원소 삭제
	*	@pre	none
	*	@post	배열의 길이를 0으로 설정
	*	@param	none
	*	@return	none
	*/
	void MakeEmpty() { m_Length = 0; }

	/*
	*	@brief	데이터를 배열에 추가
	*	@pre	배열이 동적할당 되어있어야 함
	*	@post	배열에 원소를 추가
	*	@param	추가할 해당 타입의 데이터
	*	@return	추가에 성공하면 true 반환
	*/
	bool PutItem(T& item);

	/*
	*	@brief	데이터를 배열에서 삭제
	*	@pre	배열이 동적할당 되어있어야 함
	*	@post	배열에서 원소를 삭제
	*	@param	삭제할 해당 타입의 데이터
	*	@return	삭제에 성공하면 true 반환
	*/
	bool DeleteItem(T& item);

	/*
	*	@brief	커서를 초기화
	*	@pre	none
	*	@post	커서를 -1로 설정
	*	@param	none
	*	@return	none
	*/
	void ResetList() { curIndx = -1; }

	/*
	*	@brief	커서를 기준으로 다음 원소를 반환
	*	@pre	배열에 원소가 있어야 함
	*	@post	커서가 +1됨
	*	@param	반환할 데이터
	*	@return	다음 원소를 잘 반환하였다면 true반환
	*/
	bool GetNextItem(T& item);

	/*
	*	@brief	커서를 기준으로 다음 원소의 주소값 반환
	*	@pre	배열에 원소가 있어야 함
	*	@post	커서가 +1됨
	*	@param	none
	*	@return	다음 원소의 주소값 반환
	*/
	T* GetNextItemPtr();

	/*
	*	@brief	이진탐색으로 데이터 탐색
	*	@pre	배열에 원소가 있어야 함
	*	@post	none
	*	@param	찾고자 하는 원소 데이터
	*	@return	찾았다면 해당 원소 인덱스 반환, 그렇지 않다면 -1반환
	*/
	int Retrieve(T& item);

	/*
	*	@brief	이진탐색으로 데이터 탐색
	*	@pre	배열에 원소가 있어야 함
	*	@post	none
	*	@param	찾고자 하는 원소 데이터
	*	@return	찾았다면 해당 원소 주소값 반환, 그렇지 않다면 NULL반환
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
	if (maxSize > 0) // 동적할당 배열 해제
		delete[] m_Array;
}

// 데이터를 배열에 추가
template <class T>
bool List<T>::PutItem(T& item) {
	// 배열이 가득 차있는지 확인
	if (IsFull()) {
		FullList e;
		throw e;
	}
	try {
		// 비어있는 상태에서 추가
		if (m_Length == 0) {
			m_Array[m_Length++] = item;
			return true;
		}
		else {
			// 정렬을 위해 끝에서부터 순차적으로 확인
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

// 데이터를 배열에서 삭제
template <class T>
bool List<T>::DeleteItem(T& item) {
	// 배열이 비어있는지 확인
	if (IsEmpty()) {
		EmptyList e;
		throw e;
	}
	try {
		int idx = Retrieve(item); // 삭제할 배열 원소 위치 확인
		if (idx == -1) {
			ItemNotFound e("List");
			throw e;
		}
		// 삭제
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

// 커서를 기준으로 다음 원소를 반환
template <class T>
bool List<T>::GetNextItem(T& item) {
	curIndx++;
	// 배열 끝인지 확인하고 반환
	if (curIndx < m_Length) {
		item = m_Array[curIndx];
		return true;
	}
	else
		return false;
}

// 커서를 기준으로 다음 원소의 주소값 반환
template <class T>
T* List<T>::GetNextItemPtr() {
	curIndx++;
	// 배열 끝인지 확인하고 반환
	if (curIndx < m_Length)
		return &m_Array[curIndx];
	else
		return nullptr;
}

// 이진탐색으로 데이터 탐색
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
			return mid; // 해당 데이터 인덱스 반환
		}
	}
	return -1;
}

// 이진탐색으로 데이터 탐색
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
			return &m_Array[mid]; // 해당 데이터 주소값 반환
		}
	}
	return nullptr;
}