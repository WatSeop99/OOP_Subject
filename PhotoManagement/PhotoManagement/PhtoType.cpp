#include "PhotoType.h"

PhotoType::PhotoType(std::string pName = "\0", std::string pEvent = "\0", std::string pContens = "\0") : photoName(pName), eventName(pEvent), contents(pContens)
{ }

bool PhotoType::ReadItemFromKB() {
	using namespace std;

	char temp[256];
	cout << "\t Photo Name  -->"; cin >> photoName;
	cout << "\t Event Name  -->"; cin >> eventName;
	cout << "\t Contents    -->";
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cin.getline(temp, 256);
	contents.assign(temp);
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\t  !!!  Record Read Error !!!\n";
		return false;
	}
	cin.clear();
	return true;
}

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

void PhotoType::WriteRecordToFile(std::ofstream& outFile) {
	outFile << photoName << " " << eventName << " " << contents << std::endl;
}

void PhotoType::DisplayOnScreen() {
	using namespace std;

	cout << "  " << setw(14) << photoName << setw(14) << eventName << setw(14) << contents << endl;
}

bool PhotoType::IsEventEqual(std::string name) {
	if (eventName == name)
		return true;
	else
		return false;
}

bool PhotoType::operator==(PhotoType item) {
	if (photoName == item.photoName)
		return true;
	else
		return false;
}

void PhotoType::operator=(PhotoType item) {
	photoName = item.photoName;
	eventName = item.eventName;
	contents = item.contents;
}

bool PhotoType::operator<(PhotoType item) {
	if (photoName < item.photoName)
		return true;
	else
		return false;
}

bool PhotoType::operator>(PhotoType item) {
	if (photoName > item.photoName)
		return true;
	else
		return false;
}

bool PhotoType::FindKeyFromContents(std::string key) {
	if (contents.find(key) != std::string::npos)
		return true;
	else
		return false;
}