#pragma once

#include"BasicOutputInterface.h"

#include<string>

class OutputPlayersInterface:public BasicOutputInterface {
	private:

	public:
		static void AskPlayersName(int);
		static void AskCommand(std::string);
		static void OutputPlayersInformation(std::string, int, int, int, int, int, int, int, int);
};