#include "ElementalOutputInterface.h"

void ElementalOutputInterface::AskCommand()
{
	std::cout << "	Enter option:\n";
	std::cout << "u - to use skill\n";
	std::cout << "l - to level up\n";
	std::cout << "s - to sacrifice\n";
	std::cout << "b - to return back" << std::endl;
}

void ElementalOutputInterface::OutputElementalInformation(std::string elemental_name,
	int elemntal_type, int hp, int level, int ap)
{
	std::cout << elemental_name << "\n";
	std::cout << "type: " << elemntal_type << "\n";
	std::cout << "level: " << level << "\n";
	std::cout << "ap: " << ap << "\n";
	std::cout << "hp: " << hp << std::endl;
}

void ElementalOutputInterface::OutputVoidPlace()
{
	std::cout << "There is no elemental." << std::endl;
}

void ElementalOutputInterface::AskSkill()
{
	std::cout << "1 or 2 skill:" << std::endl;
}
