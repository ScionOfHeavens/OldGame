#pragma once

#include<string>
#include<iostream>

#include"BasicOutputInterface.h"

class ElementalOutputInterface : public BasicOutputInterface{
	public:
		static void AskCommand();
		static void OutputElementalInformation(std::string,int,int,int,int);
		static void OutputVoidPlace();
		static void AskSkill();
};