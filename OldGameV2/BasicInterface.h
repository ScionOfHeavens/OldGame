#pragma once

#include<string>

#include"BasicOutputInterface.h"

class BasicInterface {
	public:
		static int TransformCharToInt(std::string);
		static bool ToReturnBack();
		static int GetFirstCoordinate(int);
		static int GetSecondCoordinate(int);
};