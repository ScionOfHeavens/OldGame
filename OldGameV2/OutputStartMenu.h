#pragma once

#include"BasicOutputInterface.h"

class OutputStartMenu:public BasicOutputInterface {
	public:
		OutputStartMenu();
		static void OutputModeChoices();
		static void AskNumberOfPlayers();
		static void AskGameBoardSize();
		static void AskFieldSize();
};