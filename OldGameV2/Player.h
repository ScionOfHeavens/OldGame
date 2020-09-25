#pragma once

#include<string>
#include<deque>

#include"ChessBoard.h"

class Player {
	private:
		std::string m_name;
		int m_light_mana;
		int m_dark_mana;
		int m_water_mana;
		int m_fire_mana;
		int m_earth_mana;
		int m_air_mana;
		int m_action_points;
		int m_total_number_of_elementals;
	public:
		Player(int);
		void MyTurn(ChessBoard&,std::deque<int>&);
		int GetActionPoints();
		int GetTotalNumberOfElements();
		std::string GetName();
		void PayForAction(std::deque<int>&);
		void TakeMana(std::deque<int>&);
		void TakeAp();
};