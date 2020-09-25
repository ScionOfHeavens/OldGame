#include "WaterElemental.h"

WaterElemental::WaterElemental(std::string players_name)
{
	m_name = "Raindrop";
	m_owner = players_name;
	m_max_hp = 20;
	m_hp = m_max_hp;
	m_ap = 0;
	m_level = 1;
	m_elemental_type = 6;
	m_air_multiplyer = 2;
	m_dark_multiplyer = 2;
	m_earth_multiplyer = 4;
	m_fire_multiplyer = 1;
	m_light_multiplyer = 2;
	m_water_multiplyer = 2;
}

void WaterElemental::UseSecondSkill(std::deque<int>& gci)
{
	m_ap -= 1;
	gci.push_back(2);
	gci.push_back(m_level);
	gci.push_back(1);
	gci.push_back(4);
}
