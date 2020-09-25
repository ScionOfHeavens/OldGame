#include "BasicInterface.h"

#include<iostream>

int BasicInterface::TransformCharToInt(std::string str)
{
	int rezult(0);
	int multiplyer(1);
	int digit;
	for (int i = 0; i < str.length(); i++) {
		digit = (int)str[0] - (int)('0');
		if ((digit >= 0) && (digit <= 9))
			rezult += multiplyer * digit;
		else
			return -1;
	}
	return rezult;
}

bool BasicInterface::ToReturnBack()
{
	std::string command;
	std::getline(std::cin, command);
	if (command == "b")
		return 1;
	else
		return 0;
}

int BasicInterface::GetFirstCoordinate(int max_x)
{
	BasicOutputInterface::AskFirstCoordinate();
	std::string str_x;
	std::getline(std::cin, str_x);
	int x = TransformCharToInt(str_x);
	if ((x < max_x)&&(x >= 0))
		return x;
	else {
		BasicOutputInterface::WrongEnter();
		return GetFirstCoordinate(max_x);
	}
}

int BasicInterface::GetSecondCoordinate(int max_y)
{
	BasicOutputInterface::AskSecondCoordinate();
	std::string str_y;
	std::getline(std::cin, str_y);
	int y = TransformCharToInt(str_y);
	if ((y < max_y) && (y >= 0))
		return y;
	else {
		BasicOutputInterface::WrongEnter();
		return GetSecondCoordinate(max_y);
	}
}
