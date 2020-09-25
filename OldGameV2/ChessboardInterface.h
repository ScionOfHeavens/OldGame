#pragma once

#include"BasicInterface.h"

#include<string>
#include<vector>

class ChessBoardInterface : public BasicInterface {
	public:
		static int GetCommand(std::string, std::vector<std::vector<std::string>>);
		static int GetFieldType(std::string);
		static void ReturnMap(std::string,std::vector<std::vector<std::string>>);
};