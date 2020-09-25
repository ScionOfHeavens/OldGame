#pragma once

#include<string>
#include<deque>

class Elemental {
	protected:
		std::string m_name;
		std::string m_owner;
		int m_block_points;
		bool m_burning_status;
		int m_elemental_type;
		int m_water_multiplyer;
		int m_fire_multiplyer;
		int m_earth_multiplyer;
		int m_air_multiplyer;
		int m_dark_multiplyer;
		int m_light_multiplyer;
		int m_level;
		int m_hp;
		int m_ap;
		int m_max_hp;
	public:
		Elemental();
		std::string GetName();
		bool ElementalOptions(std::string,std::deque<int>&);
		bool TakeDamage(int,int);
		void TakeHeal(int);
		void TakeBlock(int);
		void TakeBurning(int);
		void TakeActionPoints();
		void Level_up();
		void UseFirstSkill(std::deque<int>&);
		virtual void UseSecondSkill(std::deque<int>&);
		virtual void Sacrefice(std::deque<int>&);
		std::string GetPlayersName();
		void GiveManaToPlayers(std::deque<int>&);
		void TakeAlienAction(std::deque<int>&);
};