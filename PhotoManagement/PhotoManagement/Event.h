#pragma once

#include "Base.h"

/*
*	사진 이벤트를 관리하는 클래스
*/
class EventType : public Base {
private:
	std::string name; // 이벤트 이름
	List<std::string> nameList; // 해당 이벤트를 가지고 있는 사진들
public:
	/*
	*	@brief	constructor.
	*/
	EventType(std::string eName = "\0") : name(eName) { }

	/*
	*	@brief	destructor.
	*/
	~EventType() { }



	/*
	*	@brief	연산자 오버로딩. 이벤트 이름을 기준으로 비교
	*/
	bool operator==(const EventType& item) { return name == item.name ? true : false; }

	/*
	*	@brief	연산자 오버로딩. 이벤트 객체 대입
	*/
	void operator=(EventType& item);

	/*
	*	@brief	연산자 오버로딩. 이벤트 이름을 기준으로 비교
	*/
	bool operator<(const EventType& item) { return name < item.name ? true : false; }

	/*
	*	@brief	연산자 오버로딩. 이벤트 이름을 기준으로 비교
	*/
	bool operator>(const EventType& item) { return name > item.name ? true : false; }

	/*
	*	@brief	이벤트 이름을 설정
	*	@pre	none
	*	@post	이벤트 이름을 해당 string 객체로 설정
	*	@param	이벤트 이름을 담은 string 객체
	*	@return	none
	*/
	void SetEventName(std::string str) { name = str; }

	/*
	*	@brief	이벤트 이름 반환
	*	@pre	이벤트 이름이 초기화 되어 있어야 함
	*	@post	none
	*	@param	none
	*	@return	이벤트 이름 반환
	*/
	std::string GetEventName() { return name; }

	/*
	*	@brief	이벤트에 사진 이름을 추가
	*	@pre	중복되지 않는 사진이어야 함
	*	@post	목록에 사진 이름 추가
	*	@param	추가할 사진 이름
	*	@return	none
	*/
	void AddPhotoKey(std::string key);

	/*
	*	@brief	이벤트에 포함되어 있는 사진들을 화면에 출력
	*	@pre	리스트에 원소가 있어야 함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayDetails();

	/*
	*	@brief	사진 이름으로 이벤트 목록에서 검색
	*	@pre	리스트에 원소가 있어야 함
	*	@post	none
	*	@param	찾고자 하는 사진 이름
	*	@return	찾았으면 해당 사진의 주소값 반환
	*/
	PhotoType* FindByNameKey(std::string key);

	/*
	*	@brief	사진 내용으로 이벤트 목록에서 검색
	*	@pre	리스트에 원소가 있어야 함
	*	@post	none
	*	@param	찾고자 하는 사진 내용 키워드
	*	@return	찾았으면 해당 사진의 주소값 반환
	*/
	PhotoType* FindByContentsKey(std::string key);
};