#include "Event.h"

// 연산자 오버로딩. 이벤트 객체 대입
void EventType::operator=(EventType& item) {
	name = item.name;
	std::string* strPtr;
	item.nameList.ResetList();
	// 사진 목록 리스트 대입
	while (strPtr = item.nameList.GetNextItemPtr())
		nameList.PutItem(*strPtr);
}

// 이벤트에 사진 이름을 추가
void EventType::AddPhotoKey(std::string key) {
	if (!nameList.RetrievePtr(key)) // 중복 추가 방지
		nameList.PutItem(key);
	else
		std::cout << " 현 이벤트에 중복 사진 존재 \n";
}

// 이벤트에 포함되어 있는 사진들을 화면에 출력
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

// 사진 이름으로 이벤트 목록에서 검색
PhotoType* EventType::FindByNameKey(std::string key) {
	PhotoType ptemp(key);
	return master.RetrievePtr(ptemp);
}

// 사진 내용으로 이벤트 목록에서 검색
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