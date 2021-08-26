#pragma once

#include "PhotoType.h"
#include "list.h"

/*
*	리스트를 활용하는 클래스들의 base 클래스
*/
class Base {
protected:
	static List<PhotoType> master; // master list
};