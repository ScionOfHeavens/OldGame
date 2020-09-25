#include "Player.h"
#include "PlayerInterface.h"

Player::Player(int order_number)
{
	m_name = PlayerInterface::GetPlayersName(order_number);
	m_air_mana = 25;
	m_earth_mana = 25;
	m_fire_mana = 25;
	m_water_mana = 25;
	m_action_points = 5;
	m_light_mana = 25;
	m_dark_mana = 25;
	m_total_number_of_elementals = 0;
}

void Player::MyTurn(ChessBoard& chess_board,std::deque<int>& gci)
{
	int command;
	do {
		command = PlayerInterface::GetCommand(m_name);
		switch (command) {
		case 3:
			PlayerInterface::GetPlayersInformation(m_name, m_light_mana, m_dark_mana, m_air_mana,
				m_earth_mana, m_fire_mana, m_water_mana, m_action_points,m_total_number_of_elementals);
			break;
		case 1:
			chess_board.MapOptions(m_name,gci);
			if (gci.empty() == 0)
				return;
			break;
		}
	} while (command!=0);
}

int Player::GetActionPoints()
{
	return m_action_points;
}

int Player::GetTotalNumberOfElements()
{
	return m_total_number_of_elementals;
}

std::string Player::GetName()
{
	return m_name;
}

void Player::PayForAction(std::deque<int>& gci)
{
	m_action_points -= 1;
	int i_max = gci[0];
	gci.pop_front();
	for (int i = 0; i < i_max; i++) {
		switch (gci[0])
		{
		case 0:
			break;
		case 1:
			m_dark_mana -= gci[1];
			gci.pop_front();
			gci.pop_front();
			break;
		case 2:
			m_light_mana -= gci[1];
			gci.pop_front();
			gci.pop_front();
			break;
		case 3:
			m_air_mana -= gci[1];
			gci.pop_front();
			gci.pop_front();
			break;
		case 4:
			m_earth_mana -= gci[1];
			gci.pop_front();
			gci.pop_front();
			break;
		case 5:
			m_fire_mana -= gci[1];
			gci.pop_front();
			gci.pop_front();
			break;
		case 6:
			m_water_mana -= gci[1];
			gci.pop_front();
			gci.pop_front();
			break;
		}
	}
}

void Player::TakeMana(std::deque<int>& gci)
{
	switch (gci[0])
	{
	case 1:
		m_dark_mana += gci[1];
		break;
	case 2:
		m_light_mana += gci[1];
		break;
	case 3:
		m_air_mana += gci[1];
		break;
	case 4:
		m_earth_mana += gci[1];
		break;
	case 5:
		m_fire_mana += gci[1];
		break;
	case 6:
		m_water_mana += gci[1];
		break;
	}
	gci.pop_front();
	gci.pop_front();
}

void Player::TakeAp()
{
	m_action_points += 5;
}
