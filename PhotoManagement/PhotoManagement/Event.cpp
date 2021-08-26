#include "Event.h"

// ������ �����ε�. �̺�Ʈ ��ü ����
void EventType::operator=(EventType& item) {
	name = item.name;
	std::string* strPtr;
	item.nameList.ResetList();
	// ���� ��� ����Ʈ ����
	while (strPtr = item.nameList.GetNextItemPtr())
		nameList.PutItem(*strPtr);
}

// �̺�Ʈ�� ���� �̸��� �߰�
void EventType::AddPhotoKey(std::string key) {
	if (!nameList.RetrievePtr(key)) // �ߺ� �߰� ����
		nameList.PutItem(key);
	else
		std::cout << " �� �̺�Ʈ�� �ߺ� ���� ���� \n";
}

// �̺�Ʈ�� ���ԵǾ� �ִ� �������� ȭ�鿡 ���
void EventType::DisplayDetails() {
	nameList.ResetList();
	std::string temp;
	while (nameList.GetNextItem(temp)) {
		PhotoType ptemp;
		ptemp.SetPhotoName(temp);
		if (master.Retrieve(ptemp) != -1) {
			ptemp.DisplayOnScreen();
			break;
		}
	}
}

// ���� �̸����� �̺�Ʈ ��Ͽ��� �˻�
PhotoType* EventType::FindByNameKey(std::string key) {
	PhotoType ptemp(key);
	return master.RetrievePtr(ptemp);
}

// ���� �������� �̺�Ʈ ��Ͽ��� �˻�
PhotoType* EventType::FindByContentsKey(std::string key) {
	PhotoType* ptempPtr = nullptr;
	std::string* strPtr;
	nameList.ResetList();
	while (strPtr = nameList.GetNextItemPtr()) {
		PhotoType ptemp(*strPtr);
		ptempPtr = master.RetrievePtr(ptemp);
		if (ptempPtr) {
			if (ptempPtr->FindKeyFromContents(key))
				break;
			else
				ptempPtr = nullptr;
		}

	}
	return ptempPtr;
}