#pragma once

#include<string>

class BasicOutputInterface {
	public:
		static void EndOfWindow();
		static void WrongEnter();
		static void ToReturnBack();
		static void OutputPlayersName(std::string players_name);
		static void AskFirstCoordinate();
		static void AskSecondCoordinate();
};