#include "ChessboardInterface.h"
#include "ChessBoardOutputInterface.h"

#include<iostream>

int ChessBoardInterface::GetCommand(std::string players_name, std::vector<std::vector<std::string>> map)
{
	ReturnMap(players_name,map);
	ChessBoardOutputInterface::AskCommand();
	std::string command;
	std::getline(std::cin, command);
	ChessBoardOutputInterface::EndOfWindow();
	switch (command[0])
	{
	case 'f':
		return 1;
	case 'c':
		return 2;
	case 'b':
		return 0;
	default:
		ChessBoardOutputInterface::WrongEnter();
		return GetCommand(players_name,map);
	}
}

int ChessBoardInterface::GetFieldType(std::string players_name)
{
	ChessBoardOutputInterface::OutputPlayersName(players_name);
	ChessBoardOutputInterface::AskFieldType();
	std::string choice;
	std::getline(std::cin, choice);
	ChessBoardOutputInterface::EndOfWindow();
	switch (choice[0])
	{
		case 'b':
			return 0;
		case 'a':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'm':
			return 4;
		case 'o':
			return 5;
		case 's':
			return 6;
		case 'v':
			return 7;
		default:
			ChessBoardOutputInterface::WrongEnter();
			return GetFieldType(players_name);
	}
}

void ChessBoardInterface::ReturnMap(std::string players_name,std::vector<std::vector<std::string>> map)
{
	ChessBoardOutputInterface::OutputPlayersName(players_name);
	ChessBoardOutputInterface::OuputMap(map);
}
