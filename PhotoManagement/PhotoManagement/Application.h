#pragma once

#include "Base.h"
#include "Event.h"

/*
*	���� ������ ���� ��Ʈ�ѷ� Ŭ����
*/
class Application : public Base {
private:
	List<EventType> eventList; // �̺�Ʈ ���
	std::string inFileName; // �ܺ������� ���� istream �̸�
	std::string outFileName; // �ܺ������� ���� ostream �̸�
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
	*	@brief	���� ���� ���� �޴�
	*	@pre	none
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void Run();

	/*
	*	@brief	���� �߰�
	*	@pre	master list�� �ʱ�ȭ ���־����
	*	@post	master list�� ���� �߰�
	*	@param	none
	*	@return	none
	*/
	void AddPhoto();

	/*
	*	@brief	���� ����
	*	@pre	master list�� �ʱ�ȭ ���־����
	*	@post	master list���� ���� ����
	*	@param	none
	*	@return	none
	*/
	void DeletePhoto();

	/*
	*	@brief	���� �˻�
	*	@pre	master list�� �ʱ�ȭ ���־����
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void FindPhoto();

	/*
	*	@brief	�̺�Ʈ�� ���� �˻�
	*	@pre	master list�� �ʱ�ȭ ���־����
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void FindPhotoByEvent();

	/*
	*	@brief	��ϵǾ��ִ� ���� ����� ȭ�鿡 ���
	*	@pre	master list�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayList();

	/*
	*	@brief	���� �޴� ����
	*	@pre	none
	*	@post	command�� �ش� ������� ����
	*	@param	none
	*	@return	command�� ��ȯ
	*/
	int GetCommand();

	/*
	*	@brief	�ܺ����Ϸκ��� �����͸� �о��
	*	@pre	�о�� �ܺ������� �����ؾ���
	*	@post	none
	*	@param	none
	*	@return	�о���µ� �����ϸ� true ��ȯ
	*/
	bool ReadAllFromFile();

	/*
	*	@brief	�ܺ����Ͽ� �����͸� ��
	*	@pre	�ۼ��� �ܺ������� �����ؾ���(������ �� ����)
	*	@post	none
	*	@param	none
	*	@return	����ϴµ� �����ϸ� true ��ȯ
	*/
	bool WriteAllToFile();

	/*
	*	@brief	���������� master list�� �߰�
	*	@pre	master list�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	msater list�� ���� ������ �߰���
	*	@param	�߰��� ���� ��ü ������
	*	@return	������ �߰��ϴµ� �����ϸ� true ��ȯ
	*/
	bool AddPhotoToList(PhotoType& item);

	/*
	*	@brief	�̺�Ʈ ����Ʈ�� �̿��Ͽ� ���� ���
	*	@pre	�̺�Ʈ ����Ʈ�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayListUsingEL();

	/*
	*	@brief	���� �̸��� �̺�Ʈ�� ���� �˻�
	*	@pre	�̺�Ʈ ����Ʈ�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void SearchByPhotoNameNEvent();

	/*
	*	@brief	���� �̺�Ʈ�� �������� ���� �˻�
	*	@pre	�̺�Ʈ ����Ʈ�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void SearchByEventNContents();
};