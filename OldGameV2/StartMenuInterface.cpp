#include "StartMenuInterface.h"

#include<iostream>
#include<string>

int StartMenuInterface::ChooseMode()
{
	OutputStartMenu::OutputModeChoices();
	std::string command;//команда из стартого меню для выбора режима
	std::getline(std::cin,command);
	OutputStartMenu::EndOfWindow();
	switch (command[0])
	{
	case 's':
		return 1;
	default:
		OutputStartMenu::WrongEnter();
		return ChooseMode();
	}
}

int StartMenuInterface::GetNumberOfPlayers()
{
	OutputStartMenu::AskNumberOfPlayers();
	std::string number_of_players;
	std::getline(std::cin,number_of_players);
	OutputStartMenu::EndOfWindow();
	int number = TransformCharToInt(number_of_players);
	if(number>=0)
		return number;
	else {
		OutputStartMenu::WrongEnter();
		return GetNumberOfPlayers();
	}
}

int StartMenuInterface::GetGameBoardSize()
{
	OutputStartMenu::AskGameBoardSize();
	std::string play_board_size;
	std::getline(std::cin, play_board_size);
	OutputStartMenu::EndOfWindow();
	int number = TransformCharToInt(play_board_size);
	if (number >= 0)
		return number;
	else {
		OutputStartMenu::WrongEnter();
		return GetGameBoardSize();
	}
}

int StartMenuInterface::GetFieldSize()
{
	OutputStartMenu::AskFieldSize();
	std::string field_size;
	std::getline(std::cin, field_size);
	OutputStartMenu::EndOfWindow();
	int number = TransformCharToInt(field_size);
	if (number >= 0)
		return number;
	else {
		OutputStartMenu::WrongEnter();
		return GetFieldSize();
	}
}