#include "ChessBoardOutputInterface.h"

#include<iostream>

void ChessBoardOutputInterface::OuputMap(std::vector<std::vector<std::string>> map)
{
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			std::cout << map[i][j] << "	";
		}
		std::cout << std::endl;
	}
}

void ChessBoardOutputInterface::AskCommand()
{
	std::cout << "	Enter option:\n";
	std::cout << "f - to look at field\n";
	std::cout << "c - to change field\n";
	std::cout << "b - to return back"<<std::endl;
}

void ChessBoardOutputInterface::AskFieldType()
{
	std::cout << "Choose field type:\n";
	std::cout << "c - cloud\n";
	std::cout << "a - artificial terrain\n";
	std::cout << "d - dessert\n";
	std::cout << "m - mountain\n";
	std::cout << "o - ocean\n";
	std::cout << "v -volcano\n";
	std::cout << "b - to return back" << std::endl;
}