#include "Event.h"

void EventType::operator=(EventType& item) {
	name = item.name;
	std::string* strPtr;
	item.nameList.ResetList();
	while (strPtr = item.nameList.GetNextItemPtr())
		nameList.PutItem(*strPtr);
}

void EventType::AddPhotoKey(std::string key) {
	if (!nameList.RetrievePtr(key))
		nameList.PutItem(key);
	else
		std::cout << " 현 이벤트에 중복 사진 존재 \n";
}

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

PhotoType* EventType::FindByNameKey(std::string key) {
	PhotoType ptemp(key);
	return master.RetrievePtr(ptemp);
}

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