#pragma once

#include"BasicOutputInterface.h"

#include<vector>
#include<string>

class ChessBoardOutputInterface : public BasicOutputInterface{
	public:
		static void OuputMap(std::vector<std::vector<std::string>>);
		static void AskCommand();
		static void AskFieldType();
};