#include <iomanip>
#include "PhotoType.h"

// ������ ������ Ű����κ��� �Է¹���
bool PhotoType::ReadItemFromKB() {
	using namespace std;

	char temp[256];
	cout << "\t Photo Name  -->"; cin >> photoName;
	cout << "\t Event Name  -->"; cin >> eventName;
	cout << "\t Contents    -->";
	// �����̽� ���ڱ��� �Է¹ޱ� ���� ���� �ʱ�ȭ
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cin.getline(temp, 256);
	contents.assign(temp);
	// �Է� ���н�
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\t  !!!  Record Read Error !!!\n";
		return false;
	}
	cin.clear();
	return true;
}

// ������ ������ �ܺ����Ϸκ��� �Է¹���
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

// ������ ������ �ܺ����Ϸ� ���
void PhotoType::WriteRecordToFile(std::ofstream& outFile) {
	outFile << photoName << " " << eventName << " " << contents << std::endl;
}

// ���� ������Ƽ�� ȭ�鿡 ���
void PhotoType::DisplayOnScreen() {
	using namespace std;

	cout << "  " << setw(14) << photoName << setw(14) << eventName << setw(14) << contents << endl;
}

// ������ �����ε�. ���� ��ü ����
void PhotoType::operator=(PhotoType& item) {
	photoName = item.photoName;
	eventName = item.eventName;
	contents = item.contents;
}