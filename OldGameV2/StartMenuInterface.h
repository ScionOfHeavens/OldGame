#pragma once

#include"OutputStartMenu.h"
#include"BasicInterface.h"

class StartMenuInterface : public BasicInterface{
	public:
		static int ChooseMode();
		static int GetNumberOfPlayers();
		static int GetGameBoardSize();
		static int GetFieldSize();
};