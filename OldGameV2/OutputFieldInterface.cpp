#include "OutputFieldInterface.h"

void OutputFieldInterface::AskCommand()
{
	std::cout << "	Enter Option:\n";
	std::cout << "e - to look at elemental\n";
	std::cout << "c - to create new elemental\n";
	std::cout << "b - to return back" << std::endl;
}

void OutputFieldInterface::OuputField(std::vector<std::vector<std::string>> field)
{
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field.size(); j++) {
			std::cout << field[i][j] << "	";
		}
		std::cout << std::endl;
	}
}

void OutputFieldInterface::VoidField()
{
	std::cout << "There is no field." << std::endl;
}

void OutputFieldInterface::AskElementalType()
{
	std::cout<<"	Choose elemental type:\n";
	std::cout << "f - fire\n";
	std::cout << "w - water\n";
	std::cout << "e - earth\n";
	std::cout << "a - air\n";
	std::cout << "d - dark\n";
	std::cout << "l - light\n";
	std::cout << "b - to return back" << std::endl;
}

void OutputFieldInterface::ImposibleAction()
{
	std::cout << "You can not create elemental at this place ";
	std::cout << "because this place have already token" << std::endl;
}
