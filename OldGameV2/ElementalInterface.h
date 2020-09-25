#pragma once

#include"BasicInterface.h"

#include<string>
#include<iostream>

class ElementalInterface : public BasicInterface {
	public:
		static int GetCommand(std::string,std::string,int,int,int,int);
		static void VoidPlace();
		static int GetSkillType();
		static void ImpossibleLvlUp();
};