#pragma once

#include"BasicOutputInterface.h"

#include<string>
#include<iostream>
#include<vector>

class OutputFieldInterface : public BasicOutputInterface {
	public:
		static void AskCommand();
		static void OuputField(std::vector<std::vector<std::string>>);
		static void VoidField();
		static void AskElementalType();
		static void ImposibleAction();
};