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
	PhotoType(std::string pName = "\0", std::string pEvent = "\0", std::string pContens = "\0") : photoName(pName), eventName(pEvent), contents(pContens) { }
	~PhotoType() { }
	std::string GetPhotoName() { return photoName; }
	std::string GetEventName() { return eventName; }
	bool ReadItemFromKB();
	bool ReadRecordFromFile(std::ifstream& inFile);
	void WriteRecordToFile(std::ofstream& outFile);
	void SetPhotoName(std::string name) { photoName = name; }
	void SetEventName(std::string name) { eventName = name; }
	void DisplayOnScreen();
	bool IsEventEqual(std::string name) { return eventName == name ? true : false; }
	bool operator==(const PhotoType& item) { return photoName == item.photoName ? true : false; }
	void operator=(PhotoType& item);
	bool operator<(const PhotoType& item) { return photoName < item.photoName ? true : false; }
	bool operator>(const PhotoType& item) { return photoName > item.photoName ? true : false; }
	bool FindKeyFromContents(std::string key) { return contents.find(key) != std::string::npos ? true : false; }
};