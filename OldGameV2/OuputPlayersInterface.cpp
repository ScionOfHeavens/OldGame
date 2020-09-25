#include "OuputPlayersInterface.h"

#include<iostream>

void OutputPlayersInterface::AskPlayersName(int order_number)
{
	std::cout << "Enter "<<order_number+1<<" Players Name:";
}

void OutputPlayersInterface::AskCommand(std::string players_name)
{
	OutputPlayersName(players_name);
	std::cout << "	Enter option:\n";
	std::cout << "w - to make weather\n";
	std::cout << "m - to look at map\n";
	std::cout << "i - to get information about mana and ap\n";
	std::cout << "f - to finish turn"<<std::endl;
}

void OutputPlayersInterface::OutputPlayersInformation(std::string players_name, int lm,
	int dm, int am, int em, int fm, int wm, int ap, int tnoa)
{
	std::cout << "Information about " << players_name << ":\n";
	std::cout << "light mana = " << lm << "\n";
	std::cout << "dark mana = " << dm << "\n";
	std::cout << "air mana = " << am << "\n";
	std::cout << "earth mana = " << em << "\n";
	std::cout << "fire mana = " << fm << "\n";
	std::cout << "water mana = " << wm << "\n";
	std::cout << "action points = " << ap << "\n";
	std::cout << "total number of your elements = " << tnoa << std::endl;
}
