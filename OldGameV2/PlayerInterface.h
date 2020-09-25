#pragma once

#include<string>

#include"BasicInterface.h"

class PlayerInterface : public BasicInterface{
	public:
		static std::string GetPlayersName(int);
		static int GetCommand(std::string);
		static void GetPlayersInformation(std::string,int,int,int,int,int,int,int,int);
};