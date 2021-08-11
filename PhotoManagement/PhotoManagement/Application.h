#pragma once

#include "Base.h"
#include "Event.h"

class Application : public Base {
private:
	List<EventType> eventList;
	std::string inFileName;
	std::string outFileName;
public:
	Application(std::string filename = "test.txt") : inFileName(filename), outFileName(filename) { }
	~Application() { }
	void Run();
	void AddPhoto();
	void DeletePhoto();
	void FindPhoto();
	void FindPhotoByEvent();
	void DisplayList();
	int GetCommand();
	bool ReadAllFromFile();
	bool WriteAllToFile();
	bool AddPhotoToList(PhotoType& item);
	void DisplayListUsingEL();
	void SearchByPhotoNameNEvent();
	void SearchByEventNContents();
};