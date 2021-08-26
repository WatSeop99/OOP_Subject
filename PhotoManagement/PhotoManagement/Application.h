#pragma once

#include "Base.h"
#include "Event.h"

/*
*	사진 관리를 위한 컨트롤러 클래스
*/
class Application : public Base {
private:
	List<EventType> eventList; // 이벤트 목록
	std::string inFileName; // 외부파일을 위한 istream 이름
	std::string outFileName; // 외부파일을 위한 ostream 이름
public:
	/*
	*	@brief	constructor.
	*/
	Application(std::string filename = "test.txt") : inFileName(filename), outFileName(filename) { }
	
	/*
	*	@brief	destructor.
	*/
	~Application() { }



	/*
	*	@brief	사진 관리 실행 메뉴
	*	@pre	none
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void Run();

	/*
	*	@brief	사진 추가
	*	@pre	master list가 초기화 되있어야함
	*	@post	master list에 사진 추가
	*	@param	none
	*	@return	none
	*/
	void AddPhoto();

	/*
	*	@brief	사진 삭제
	*	@pre	master list가 초기화 되있어야함
	*	@post	master list에서 사진 삭제
	*	@param	none
	*	@return	none
	*/
	void DeletePhoto();

	/*
	*	@brief	사진 검색
	*	@pre	master list가 초기화 되있어야함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void FindPhoto();

	/*
	*	@brief	이벤트로 사진 검색
	*	@pre	master list가 초기화 되있어야함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void FindPhotoByEvent();

	/*
	*	@brief	등록되어있는 사진 목록을 화면에 출력
	*	@pre	master list에 원소가 있어야 함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayList();

	/*
	*	@brief	실행 메뉴 선택
	*	@pre	none
	*	@post	command를 해당 명령으로 설정
	*	@param	none
	*	@return	command를 반환
	*/
	int GetCommand();

	/*
	*	@brief	외부파일로부터 데이터를 읽어옴
	*	@pre	읽어올 외부파일이 존재해야함
	*	@post	none
	*	@param	none
	*	@return	읽어오는데 성공하면 true 반환
	*/
	bool ReadAllFromFile();

	/*
	*	@brief	외부파일에 데이터를 씀
	*	@pre	작성할 외부파일이 존재해야함(생성할 수 있음)
	*	@post	none
	*	@param	none
	*	@return	출력하는데 성공하면 true 반환
	*/
	bool WriteAllToFile();

	/*
	*	@brief	사진파일을 master list에 추가
	*	@pre	master list가 초기화 되어있어야 함
	*	@post	msater list에 사진 파일이 추가됨
	*	@param	추가할 사진 객체 데이터
	*	@return	파일을 추가하는데 성공하면 true 반환
	*/
	bool AddPhotoToList(PhotoType& item);

	/*
	*	@brief	이벤트 리스트를 이용하여 사진 출력
	*	@pre	이벤트 리스트에 원소가 있어야 함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayListUsingEL();

	/*
	*	@brief	사진 이름과 이벤트로 사진 검색
	*	@pre	이벤트 리스트에 원소가 있어야 함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void SearchByPhotoNameNEvent();

	/*
	*	@brief	사진 이벤트와 내용으로 사진 검색
	*	@pre	이벤트 리스트에 원소가 있어야 함
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void SearchByEventNContents();
};