#include "OutputStartMenu.h"

#include<iostream>

OutputStartMenu::OutputStartMenu() {

}

void OutputStartMenu::OutputModeChoices()
{
	std::cout << "   Enter option:\n";
	std::cout << "s-to start a new game\n";
	std::cout << "c-to create a tests fields\n";
	std::cout << "h-to get help description about other options and game rules" << std::endl;
}

void OutputStartMenu::AskNumberOfPlayers()
{
	std::cout << "Enter number of players: ";
}

void OutputStartMenu::AskGameBoardSize()
{
	std::cout << "Enter game board size: ";
}

void OutputStartMenu::AskFieldSize()
{
	std::cout << "Enter field size: ";
}
