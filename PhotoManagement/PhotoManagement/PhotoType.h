#pragma once
#include <iostream>
#include <string>
#include <fstream>

/*
*	������ ����, ����� ����ִ� Ŭ����
*/
class PhotoType {
private:
	std::string photoName; // ���� �̸�
	std::string eventName; // ���� �̺�Ʈ
	std::string contents; // ���� ����
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
	*	@brief	���� �̸� ��ȯ
	*	@pre	���� �̸��� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	���� �̸� ��ȯ
	*/
	std::string GetPhotoName() { return photoName; }

	/*
	*	@brief	���� �̺�Ʈ ��ȯ
	*	@pre	���� �̺�Ʈ�� �ʱ�ȭ �Ǿ� �־�� ��
	*	@post	none
	*	@param	none
	*	@return	���� �̺�Ʈ ��ȯ
	*/
	std::string GetEventName() { return eventName; }

	/*
	*	@brief	������ ������ Ű����κ��� �Է¹���
	*	@pre	none
	*	@post	���� �̸�, �̺�Ʈ, ������ �Է°����� ������
	*	@param	none
	*	@return	�Է¹޴µ� �����ϸ� true ��ȯ
	*/
	bool ReadItemFromKB();

	/*
	*	@brief	������ ������ �ܺ����Ϸκ��� �Է¹���
	*	@pre	�ܺ������� �־�� ��
	*	@post	�ܺ����Ϸκ��� �о�� �����͸� ������� ���� ������Ƽ�� ������
	*	@param	�����͸� �б� ���� istream ��ü
	*	@return	�Է¹޴µ� �����ϸ� true ��ȯ
	*/
	bool ReadRecordFromFile(std::ifstream& inFile);

	/*
	*	@brief	������ ������ �ܺ����Ϸ� ���
	*	@pre	�ܺ������� �־�� ��(������ �� ����)
	*	@post	������ ������Ƽ�� ���ʷ� �ܺ����Ͽ� �ۼ�
	*	@param	�����͸� ���� ���� ostream ��ü
	*	@return	����ϴµ� �����ϸ� true ��ȯ
	*/
	void WriteRecordToFile(std::ofstream& outFile);

	/*
	*	@brief	���� �̸��� ����
	*	@pre	none
	*	@post	���� �̸��� �ش� string ��ü�� ����
	*	@param	���� �̸��� ���� string ��ü
	*	@return	none
	*/
	void SetPhotoName(std::string name) { photoName = name; }

	/*
	*	@brief	���� �̺�Ʈ�� ����
	*	@pre	none
	*	@post	���� �̺�Ʈ�� �ش� string ��ü�� ����
	*	@param	���� �̺�Ʈ�� ���� string ��ü
	*	@return	none
	*/
	void SetEventName(std::string name) { eventName = name; }

	/*
	*	@brief	���� ������Ƽ�� ȭ�鿡 ���
	*	@pre	���� ������Ƽ�� �ʱ�ȭ�Ǿ��־�� ��
	*	@post	none
	*	@param	none
	*	@return	none
	*/
	void DisplayOnScreen();

	/*
	*	@brief	���� �̺�Ʈ�� �������� �ش� �̺�Ʈ�̸��� ������ Ȯ��
	*	@pre	���� �̺�Ʈ�� �ʱ�ȭ �Ǿ��־�� ��
	*	@post	none
	*	@param	none
	*	@return	���� �̺�Ʈ�� �ش� �̺�Ʈ ��ü�� ���ٸ� true ��ȯ
	*/
	bool IsEventEqual(std::string name) { return eventName == name ? true : false; }

	/*
	*	@brief	������ �����ε�. �����̸��� �������� ��
	*/
	bool operator==(const PhotoType& item) { return photoName == item.photoName ? true : false; }
	
	/*
	*	@brief	������ �����ε�. ���� ��ü ����
	*/
	void operator=(PhotoType& item);

	/*
	*	@brief	������ �����ε�. ���� �̸��� �������� ��
	*/
	bool operator<(const PhotoType& item) { return photoName < item.photoName ? true : false; }
	
	/*
	*	@brief	������ �����ε�. ���� �̸��� �������� ��
	*/
	bool operator>(const PhotoType& item) { return photoName > item.photoName ? true : false; }
	
	/*
	*	@brief	���� ���뿡�� Ű���� �˻�
	*	@pre	���� ������ �ʱ�ȭ �Ǿ��־�� ��
	*	@post	none
	*	@param	ã�� Ű���� string ��ü
	*	@return	���� ���뿡�� Ű���带 ã�� �� �ִٸ� true ��ȯ
	*/
	bool FindKeyFromContents(std::string key) { return contents.find(key) != std::string::npos ? true : false; }
};