#include "BasicOutputInterface.h"

#include <iostream>

void BasicOutputInterface::EndOfWindow()
{
	std::cout << "________________________________________________________________________________________________________________________" << std::endl;
}

void BasicOutputInterface::WrongEnter()
{
	std::cout << "You entered smth wrong. Try again." << std::endl;
}

void BasicOutputInterface::ToReturnBack()
{
	std::cout << "Enter b - to return back: ";
}

void BasicOutputInterface::OutputPlayersName(std::string players_name)
{
	std::cout << players_name << "'s turn:" << std::endl;
}

void BasicOutputInterface::AskFirstCoordinate()
{
	std::cout << "Enter first coordinate: ";
}

void BasicOutputInterface::AskSecondCoordinate()
{
	std::cout << "Enter second coordinate: ";
}
