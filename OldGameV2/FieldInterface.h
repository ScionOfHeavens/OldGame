#pragma once

#include"BasicInterface.h"

#include<string>
#include<iostream>
#include<vector>

class FieldInterface : public BasicInterface {
	public:
		static int GetCommand(std::string,std::vector<std::vector<std::string>>);
		static void VoidField();
		static int GetElementalType(std::string);
		static void ImposibleAction();
		static void OutputMap(std::string,std::vector<std::vector<std::string>>);
};