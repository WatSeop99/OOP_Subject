#pragma once

#include "Base.h"

class EventType : public Base {
private:
	std::string name;
	List<std::string> nameList;
public:
	EventType(std::string eName = "\0") : name(eName) { }
	~EventType() { }
	bool operator==(const EventType& item);
	void operator=(EventType& item);
	bool operator<(const EventType& item);
	bool operator>(const EventType& item);
	void SetEventName(std::string str) { name = str; }
	std::string GetEventName() { return name; }
	void AddPhotoKey(std::string key);
	void DisplayDetails();
	PhotoType* FindByNameKey(std::string key);
	PhotoType* FindByContentsKey(std::string key);
};