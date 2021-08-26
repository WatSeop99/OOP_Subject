#pragma once
#include <iostream>
#include <string>
#include <fstream>

/*
*	사진의 정보, 기능을 담고있는 클래스
*/
class PhotoType {
private:
	std::string photoName; // 사진 이름
	std::string eventName; // 사진 이벤트
	std::string contents; // 사진 내용
public:
	/*
	*	@brief	constructor.
	*/
	PhotoType(std::string pName = "\0", std::string pEvent = "\0", std::string pContens = "\0") : photoName(pName), eventName(pEvent), contents(pContens) { }
	
	/*
	*	@brief	destructor.
	*/
	~PhotoType() { }



	/*
	*	@brief	사진 이름 반환
	*	@pre	사진 이름이 초기화 되어 있어야 함
	*	@post	none
	*	@param	none
	*	@return	사진 이름 반환
	*/
	std::string GetPhotoName() { return photoName; }

	/*
	*	@brief	사진 이벤트 반환
	*	@pre	사진 이벤트가 초기화 되어 있어야 함
	*	@post	none
	*	@param	none
	*	@return	사진 이벤트 반환
	*/
	std::string GetEventName() { return eventName; }

	/*
	*	@brief	사진의 정보를 키보드로부터 입력받음
	*	@pre	none
	*	@post	사진 이름, 이벤트, 내용이 입력값으로 설정됨
	*	@param	none
	*	@return	입력받는데 성공하면 true 반환
	*/
	bool ReadItemFromKB();

	/*
	*	@brief	사진의 정보를 외부파일로부터 입력받음
	*	@pre	외부파일이 있어야 함
	*	@post	외부파일로부터 읽어온 데이터를 기반으로 사진 프로퍼티가 설정됨
	*	@param	데이터를 읽기 위한 istream 객체
	*	@return	입력받는데 성공하면 true 반환
	*/
	bool ReadRecordFromFile(std::ifstream& inFile);

	/*
	*	@brief	사진의 정보를 외부파일로 출력
	*	@pre	외부파일이 있어야 함(생성할 수 있음)
	*	@post	사진의 프로퍼티를 차례로 외부파일에 작성
	*	@param	데이터를 쓰기 위한 ostream 객체
	*	@return	출력하는데 성공하면 true 반환
	*/
	void WriteRecordToFile(std::ofstream& outFile);

	/*
	*	@brief	사진 이름을 설정
	*	@pre	none
	*	@post	사진 이름을 해당 string 객체로 설정
	*	@param	사진 이름을 담은 string 객체
	*	@return	none
	*/
	void SetPhotoName(std::string name) { photoName = name; }

	/*
	*	@brief	사진 이벤트를 설정
	*	@pre	none
	*	@post	사진 이벤트를 해당 string 객체로 설정
	*	@param	사진 이벤트를 담은 string 객체
	*	@return	none
	*/
	void SetEventName(std::string name) { eventName = name; }

	/*
	*	@brief	사진 프로퍼티를 화면에 출력
	*	@pre	사진 프로퍼티가 초기화되어있어야 함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayOnScreen();

	/*
	*	@brief	사진 이벤트를 기준으로 해당 이벤트이름과 같은지 확인
	*	@pre	사진 이벤트가 초기화 되어있어야 함
	*	@post	none
	*	@param	none
	*	@return	사진 이벤트와 해당 이벤트 객체가 같다면 true 반환
	*/
	bool IsEventEqual(std::string name) { return eventName == name ? true : false; }

	/*
	*	@brief	연산자 오버로딩. 사진이름을 기준으로 비교
	*/
	bool operator==(const PhotoType& item) { return photoName == item.photoName ? true : false; }
	
	/*
	*	@brief	연산자 오버로딩. 사진 객체 대입
	*/
	void operator=(PhotoType& item);

	/*
	*	@brief	연산자 오버로딩. 사진 이름을 기준으로 비교
	*/
	bool operator<(const PhotoType& item) { return photoName < item.photoName ? true : false; }
	
	/*
	*	@brief	연산자 오버로딩. 사진 이름을 기준으로 비교
	*/
	bool operator>(const PhotoType& item) { return photoName > item.photoName ? true : false; }
	
	/*
	*	@brief	사진 내용에서 키워드 검색
	*	@pre	사진 내용이 초기화 되어있어야 함
	*	@post	none
	*	@param	찾을 키워드 string 객체
	*	@return	사진 내용에서 키워드를 찾을 수 있다면 true 반환
	*/
	bool FindKeyFromContents(std::string key) { return contents.find(key) != std::string::npos ? true : false; }
};