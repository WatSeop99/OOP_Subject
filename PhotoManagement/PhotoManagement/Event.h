#pragma once

#include "Base.h"

/*
*	���� �̺�Ʈ�� �����ϴ� Ŭ����
*/
class EventType : public Base {
private:
	std::string name; // �̺�Ʈ �̸�
	List<std::string> nameList; // �ش� �̺�Ʈ�� ������ �ִ� ������
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
	*	@brief	������ �����ε�. �̺�Ʈ �̸��� �������� ��
	*/
	bool operator==(const EventType& item) { return name == item.name ? true : false; }

	/*
	*	@brief	������ �����ε�. �̺�Ʈ ��ü ����
	*/
	void operator=(EventType& item);

	/*
	*	@brief	������ �����ε�. �̺�Ʈ �̸��� �������� ��
	*/
	bool operator<(const EventType& item) { return name < item.name ? true : false; }

	/*
	*	@brief	������ �����ε�. �̺�Ʈ �̸��� �������� ��
	*/
	bool operator>(const EventType& item) { return name > item.name ? true : false; }

	/*
	*	@brief	�̺�Ʈ �̸��� ����
	*	@pre	none
	*	@post	�̺�Ʈ �̸��� �ش� string ��ü�� ����
	*	@param	�̺�Ʈ �̸��� ���� string ��ü
	*	@return	none
	*/
	void SetEventName(std::string str) { name = str; }

	/*
	*	@brief	�̺�Ʈ �̸� ��ȯ
	*	@pre	�̺�Ʈ �̸��� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	�̺�Ʈ �̸� ��ȯ
	*/
	std::string GetEventName() { return name; }

	/*
	*	@brief	�̺�Ʈ�� ���� �̸��� �߰�
	*	@pre	�ߺ����� �ʴ� �����̾�� ��
	*	@post	��Ͽ� ���� �̸� �߰�
	*	@param	�߰��� ���� �̸�
	*	@return	none
	*/
	void AddPhotoKey(std::string key);

	/*
	*	@brief	�̺�Ʈ�� ���ԵǾ� �ִ� �������� ȭ�鿡 ���
	*	@pre	����Ʈ�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayDetails();

	/*
	*	@brief	���� �̸����� �̺�Ʈ ��Ͽ��� �˻�
	*	@pre	����Ʈ�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	ã���� �ϴ� ���� �̸�
	*	@return	ã������ �ش� ������ �ּҰ� ��ȯ
	*/
	PhotoType* FindByNameKey(std::string key);

	/*
	*	@brief	���� �������� �̺�Ʈ ��Ͽ��� �˻�
	*	@pre	����Ʈ�� ���Ұ� �־�� ��
	*	@post	none
	*	@param	ã���� �ϴ� ���� ���� Ű����
	*	@return	ã������ �ش� ������ �ּҰ� ��ȯ
	*/
	PhotoType* FindByContentsKey(std::string key);
};