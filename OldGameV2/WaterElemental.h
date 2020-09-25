#pragma once

#include"Basic_Elemental.h"

#include<string>

class WaterElemental : public Elemental {
	public:
		WaterElemental(std::string);
		virtual void UseSecondSkill(std::deque<int>& gci);
};