#include <iomanip>
#include "PhotoType.h"

// 사진의 정보를 키보드로부터 입력받음
bool PhotoType::ReadItemFromKB() {
	using namespace std;

	char temp[256];
	cout << "\t Photo Name  -->"; cin >> photoName;
	cout << "\t Event Name  -->"; cin >> eventName;
	cout << "\t Contents    -->";
	// 스페이스 문자까지 입력받기 위해 버퍼 초기화
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cin.getline(temp, 256);
	contents.assign(temp);
	// 입력 실패시
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\t  !!!  Record Read Error !!!\n";
		return false;
	}
	cin.clear();
	return true;
}

// 사진의 정보를 외부파일로부터 입력받음
bool PhotoType::ReadRecordFromFile(std::ifstream& inFile) {
	char temp[256];
	inFile >> photoName >> eventName;
	inFile.getline(temp, 255);
	contents.assign(temp);

	if (inFile.fail())
		return false;
	inFile.clear();
	return true;
}

// 사진의 정보를 외부파일로 출력
void PhotoType::WriteRecordToFile(std::ofstream& outFile) {
	outFile << photoName << " " << eventName << " " << contents << std::endl;
}

// 사진 프로퍼티를 화면에 출력
void PhotoType::DisplayOnScreen() {
	using namespace std;

	cout << "  " << setw(14) << photoName << setw(14) << eventName << setw(14) << contents << endl;
}

// 연산자 오버로딩. 사진 객체 대입
void PhotoType::operator=(PhotoType& item) {
	photoName = item.photoName;
	eventName = item.eventName;
	contents = item.contents;
}