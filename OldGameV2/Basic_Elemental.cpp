#include "Basic_Elemental.h"
#include "ElementalInterface.h"

Elemental::Elemental()
{
	m_name = "Void";
	m_elemental_type = 0;
}

std::string Elemental::GetName()
{
	return m_name;
}

bool Elemental::ElementalOptions(std::string players_name,std::deque<int>&gci)
{
	if (m_elemental_type == 0) {
		ElementalInterface::VoidPlace();
		return false;
	}

	int command = ElementalInterface::GetCommand(players_name,m_name,m_elemental_type, m_level,m_hp,m_ap);
	switch (command)
	{
		case 0:
			return false;
		case 1:
			if ((m_level < 3) && (m_air_multiplyer > 0))
				Level_up();
			else
				ElementalInterface::ImpossibleLvlUp();
			return false;
		case 2:
		{
			int skill = ElementalInterface::GetSkillType();
			switch (skill)
			{
			case 1:
				UseFirstSkill(gci);
				break;
			case 2:
				UseSecondSkill(gci);
				break;
			}
			return false;
		}
		case 3:
		{
			Sacrefice(gci);
			return true;
		}
	}
}

bool Elemental::TakeDamage(int type, int num_of_dam)
{
	if (m_block_points > num_of_dam) {
		m_block_points -= num_of_dam;
		return false;
	}
	else {
		num_of_dam -= m_block_points;
		m_block_points = 0;
	}
	switch (type)
	{
	case 1:
		m_hp -= num_of_dam * m_dark_multiplyer;
		break;
	case 2:
		m_hp -= num_of_dam * m_light_multiplyer;
		break;
	case 3:
		m_hp -= num_of_dam * m_air_multiplyer;
		break;
	case 4:
		m_hp -= num_of_dam * m_earth_multiplyer;
		break;
	case 5:
		m_hp -= num_of_dam * m_fire_multiplyer;
		break;
	case 6:
		m_hp -= num_of_dam * m_water_multiplyer;
		break;
	}
	if (m_hp <= 0)
		return true;
	return false;
}

void Elemental::TakeHeal(int heal)
{
	m_hp += heal;

	if (m_hp >= m_max_hp)
		m_hp = m_max_hp;
}

void Elemental::TakeBlock(int block_points)
{
	m_block_points += block_points;
}

void Elemental::TakeBurning(int)
{
	m_burning_status = 1;
}

void Elemental::TakeActionPoints()
{
	m_ap += 1;
}

void Elemental::Level_up()
{
	m_level += 1;
	m_ap -= 1;
}

void Elemental::UseFirstSkill(std::deque<int>& gci)
{
	gci.push_back(2);
	gci.push_back(m_level);
	gci.push_back(0);
	gci.push_back(m_elemental_type);
	gci.push_back(2);
}

void Elemental::UseSecondSkill(std::deque<int>& gci)
{

}

void Elemental::Sacrefice(std::deque<int>& gci)
{

}

std::string Elemental::GetPlayersName()
{
	return m_owner;
}

void Elemental::GiveManaToPlayers(std::deque<int>& gci)
{
	gci.push_back(1);
	gci.push_back(m_elemental_type);
	gci.push_back(m_level);
}

void Elemental::TakeAlienAction(std::deque<int>& gci)
{
	switch (gci[0])
	{
		gci.pop_front();
	case 0:
		TakeDamage(gci[0],gci[1]);
		gci.pop_front();
		gci.pop_front();
		return;
	case 1:
		TakeHeal(gci[0]);
		gci.pop_front();
		return;
	}
}
