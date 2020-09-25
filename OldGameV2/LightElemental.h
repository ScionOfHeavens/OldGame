#pragma once

#include"Basic_Elemental.h"

#include<string>

class LightElemental : public Elemental {
	public:
		LightElemental(std::string);
		virtual void UseSecondSkill(std::deque<int>&);
};