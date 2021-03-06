#include <iomanip>
#include "Application.h"

List<PhotoType> Base::master; // static 변수 초기화

// 사진 관리 실행 메뉴
void Application::Run() {
	using namespace std;

	int command;
	while (command = GetCommand()) {
		cout.setf(ios::left, ios::adjustfield);
		switch (command) {
		case 0:
			return;
		case 1:
			AddPhoto(); // 사진 추가
			break;
		case 2:
			DeletePhoto(); // 사진 삭제
			break;
		case 3:
			FindPhoto(); // 사진 검색
			break;
		case 4:
			FindPhotoByEvent(); // 이벤트로 사진 검색
			break;
		case 5:
			DisplayList(); // 사진 목록 출력
			break;
		case 6:
			ReadAllFromFile(); // 외부파일로부터 데이터 읽기
			break;
		case 7:
			WriteAllToFile(); // 외부파일에 데이터 쓰기
			break;
		case 8:
			DisplayListUsingEL(); // 이벤트 리스트를 이용하여 사진목록 출력
			break;
		case 9:
			SearchByPhotoNameNEvent(); // 사진 이름과 이벤트로 검색
			break;
		case 10:
			SearchByEventNContents(); // 사진 이벤트와 내용으로 검색
			break;
		default:
			cout << "Invalid operation \n";
		}
	}
}

// 사진 추가
void Application::AddPhoto() {
	PhotoType input;
	if (!input.ReadItemFromKB()) // 사진 정보 입력
		return;
	AddPhotoToList(input);
}

// 사진 삭제
void Application::DeletePhoto() {
	std::string name;
	std::cout << "\t 삭제할 사진명 입력 -->";
	std::cin >> name;

	PhotoType record(name);
	master.DeleteItem(record);
}

// 사진 검색
void Application::FindPhoto() {
	std::string name;
	std::cout << "\t 찾고자 하는 사진명 입력 --> ";
	std::cin >> name;
	
	PhotoType record(name), *pPtr;
	pPtr = master.RetrievePtr(record);
	if (!pPtr)
		std::cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
	else
		pPtr->DisplayOnScreen();
}

// 이벤트로 사진 검색
void Application::FindPhotoByEvent() {
	using namespace std;

	string eName;
	cout << "\t 찾고자 하는 이벤트 명 입력 --> ";
	cin >> eName;

	PhotoType record;
	bool found = false;
	cout << "\t" << "  " << setw(14) << "[사진명]" << setw(14) << "[이벤트 명]" << setw(14) << "[사진 설명]" << endl;
	master.ResetList();
	while (master.GetNextItem(record)) {
		if (record.IsEventEqual(eName)) {
			cout << '\t';
			record.DisplayOnScreen();
			found = true;
		}
	}
	if (!found)
		cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
}

// 등록되어있는 사진 목록을 화면에 출력
void Application::DisplayList() {
	using namespace std;

	cout << "\t ***  사진 리스트 화면 출력  ***\n";
	cout << "\t" << "  " << setw(14) << "[사진 명]" << setw(14) << "[이벤트명]" << setw(14) << "[사진 설명]" << endl;

	PhotoType record;
	master.ResetList();
	while (master.GetNextItem(record)) {
		cout << '\t';
		record.DisplayOnScreen();
	}
}

// 실행 메뉴 선택
int Application::GetCommand() {
	using namespace std;

	int temp;
	while (1)
	{
		cout << "\n\t--- ID ------------ 수행할 작업 --------------------" << endl;
		cout.setf(ios::left, ios::adjustfield);
		cout << "\t|" << setw(50) << "    0. 프로그램 종료" << "|\n";
		cout << "\t|" << setw(50) << "    1. 새 사진 추가" << "|\n";
		cout << "\t|" << setw(50) << "    2. 사진 삭제" << "|\n";
		cout << "\t|" << setw(50) << "    3. 사진 이름으로 검색" << "|\n";
		cout << "\t|" << setw(50) << "    4. 이벤트 이름으로 검색" << "|\n";
		cout << "\t|" << setw(50) << "    5. 리스트의 모든 사진을 화면에 출력" << "|\n";
		cout << "\t|" << setw(50) << "    6. 파일에서 모든 사진 읽기" << "|\n";
		cout << "\t|" << setw(50) << "    7. 리스트의 모든 사진을 파일에 출력" << "|\n";
		cout << "\t|" << setw(50) << "    8. event list를 이용한 이벤트 검색" << "|\n";
		cout << "\t|" << setw(50) << "    9. 이벤명과 사진명으로 검색" << "|\n";
		cout << "\t|" << setw(50) << "    10.이벤명과 관련 키워드로 검색" << "|\n";
		cout << "\t----------------------------------------------------" << endl;
		cout << "\t 수행할 작업 선택 --> ";
		if (cin.fail() || !(cin >> temp) || temp < 0 || temp>10) {	// input fail or input value is out of bound
			cout << "\t    ### 유효하지 않은 명령. 다시 입력하세요  ####" << endl;
			cin.clear();	//clear flag
			cin.ignore(INT_MAX, '\n');	//empty input buffer
		}
		else {
			cin.clear();  // clear flag
			cin.ignore(INT_MAX, '\n');  // empty input buffer
			return temp;
		}
	}
}

// 외부파일로부터 데이터를 읽어옴
bool Application::ReadAllFromFile() {
	using namespace std;

	string photoName, eventName;
	master.MakeEmpty();
	ifstream inFile;
	inFile.open(inFileName);
	// 외부파일 읽기 실패시
	if (!inFile.is_open()) {
		cout << "Unable to Open input file" << endl;
		return false;
	}

	PhotoType record;
	while (record.ReadRecordFromFile(inFile))
		AddPhotoToList(record);
	return true;
}

// 외부파일에 데이터를 씀
bool Application::WriteAllToFile() {
	using namespace std;

	ofstream outFile;
	outFile.open(outFileName);
	// 외부파일 읽기 실패시
	if (!outFile.is_open()) {
		cout << "Unable to Open output file" << endl;
		return false;
	}

	PhotoType record;
	master.ResetList();
	while (master.GetNextItem(record))
		record.WriteRecordToFile(outFile);
	return true;
}

// 사진파일을 master list에 추가
bool Application::AddPhotoToList(PhotoType& item) {
	// master list에 사진 중복 추가 방지
	if (!master.GetLength()) // 사진이 없다면
		master.PutItem(item);
	else {
		int found = master.Retrieve(item); // 중복 체크
		if (found == -1)
			master.PutItem(item);
		else
			return false;
	}

	// event list에 사진 중복 추가 방지
	if (!eventList.GetLength()) { // 사진이 없다면
		EventType record(item.GetEventName());
		record.AddPhotoKey(item.GetPhotoName());
		eventList.PutItem(record);
	}
	else {
		EventType record(item.GetEventName()), *ptr;
		ptr = eventList.RetrievePtr(record); // 중복 체크
		if (!ptr) {
			record.AddPhotoKey(item.GetPhotoName());
			eventList.PutItem(record);
		}
		else
			ptr->AddPhotoKey(item.GetEventName());
	}
	return true;
}

// 이벤트 리스트를 이용하여 사진 출력
void Application::DisplayListUsingEL() {
	std::string name;
	std::cout << "\t 찾고자 하는 이벤트 명 입력 --> ";
	std::cin >> name;

	EventType record(name), *ptr;
	ptr = eventList.RetrievePtr(record);
	if (ptr)
		ptr->DisplayDetails();
	else
		std::cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
}

// 사진 이름과 이벤트로 사진 검색
void Application::SearchByPhotoNameNEvent() {
	std::string pName, eName;
	std::cout << "\t << 이벤트와 사진명로 사진 검색  >>\n \t검색할 사진의 이벤트와 사진명을 입력하세요 --> ";
	std::cin >> eName >> pName;

	EventType record(eName), *ePtr;
	PhotoType* pPtr;
	ePtr = eventList.RetrievePtr(record);
	if (ePtr) {
		pPtr = ePtr->FindByNameKey(pName);
		if (pPtr)
			pPtr->DisplayOnScreen();
		else
			std::cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
	}
	else
		std::cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
}

// 사진 이벤트와 내용으로 사진 검색
void Application::SearchByEventNContents() {
	std::string eName, contents;
	std::cout << "\t << 이벤트와 내용관련 단어로 사진 검색  >>\n \t검색할 사진의 이벤트와 내용 단어를 입력하세요 --> ";
	std::cin >> eName >> contents;

	EventType record(eName), *ePtr;
	PhotoType* pPtr;
	ePtr = eventList.RetrievePtr(record);
	if (ePtr) {
		pPtr = ePtr->FindByContentsKey(contents);
		if (pPtr)
			pPtr->DisplayOnScreen();
		else
			std::cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
	}
	else
		std::cout << "\n%%%% 일치하는 사진을 찾지 못했습니다 %%%%\n";
}