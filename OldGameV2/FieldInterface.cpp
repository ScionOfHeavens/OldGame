#include "FieldInterface.h"
#include"OutputFieldInterface.h"

int FieldInterface::GetCommand(std::string players_name,std::vector<std::vector<std::string>>field)
{
	OutputMap(players_name, field);
	OutputFieldInterface::AskCommand();
	std::string command;
	std::getline(std::cin, command);
	OutputFieldInterface::EndOfWindow();
	switch (command[0])
	{
		case 'b':
			return 0;
		case 'e':
			return 1;
		case 'c':
			return 2;
	default:
		OutputFieldInterface::WrongEnter();
		return GetCommand(players_name,field);
	}
}

void FieldInterface::VoidField()
{
	OutputFieldInterface::VoidField();
	OutputFieldInterface::ToReturnBack();
	bool b = ToReturnBack();
	OutputFieldInterface::EndOfWindow();
	if (b == 1)
		return;
	else {
		OutputFieldInterface::WrongEnter();
		VoidField();
	}
	return;
}

int FieldInterface::GetElementalType(std::string players_name)
{
	OutputFieldInterface::OutputPlayersName(players_name);
	OutputFieldInterface::AskElementalType();
	std::string type;
	std::getline(std::cin, type);
	OutputFieldInterface::EndOfWindow();
	switch (type[0])
	{
		case 'b':
			return 0;
		case 'd':
			return 1;
		case 'l':
			return 2;
		case 'w':
			return 3;
		case 'f':
			return 4;
		case 'e':
			return 5;
		case 'a':
			return 6;
	default:
		OutputFieldInterface::WrongEnter();
		return GetElementalType(players_name);
	}
	return 0;
}

void FieldInterface::ImposibleAction()
{
	OutputFieldInterface::ImposibleAction();
}

void FieldInterface::OutputMap(std::string players_name, std::vector<std::vector<std::string>> field)
{
	OutputFieldInterface::OutputPlayersName(players_name);
	OutputFieldInterface::OuputField(field);
}
