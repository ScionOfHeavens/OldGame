#include "FireElemental.h"

FireElemental::FireElemental(std::string players_name)
{
	m_name = "Spark";
	m_owner = players_name;
	m_max_hp = 20;
	m_hp = m_max_hp;
	m_ap = 0;
	m_level = 1;
	m_elemental_type = 5;
	m_air_multiplyer = 1;
	m_dark_multiplyer = 2;
	m_earth_multiplyer = 2;
	m_fire_multiplyer = 2;
	m_light_multiplyer = 2;
	m_water_multiplyer = 4;
}
