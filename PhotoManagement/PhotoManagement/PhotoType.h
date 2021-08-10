#pragma once
#include <iostream>
#include <string>
#include <fstream>

class PhotoType {
private:
	std::string photoName;
	std::string eventName;
	std::string contents;
public:
	PhotoType(std::string pName = "\0", std::string pEvent = "\0", std::string pContents = "\0");
	~PhotoType() { }
	std::string GetPhotoName() { return photoName; }
	std::string GetEventName() { return eventName; }
	bool ReadItemFromKB();
	bool ReadRecordFromFile(std::ifstream& inFile);
	void WriteRecordToFile(std::ofstream& outFile);
	void SetPhotoName(std::string name) { photoName = name; }
	void SetEventName(std::string name) { eventName = name; }
	void DisplayOnScreen();
	bool IsEventEqual(std::string name);
	bool operator==(PhotoType item);
	void operator=(PhotoType item);
	bool operator<(PhotoType item);
	bool operator>(PhotoType item);
	bool FindKeyFromContents(std::string key);
};