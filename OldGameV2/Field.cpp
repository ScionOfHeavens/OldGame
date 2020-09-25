#include "Field.h"
#include "FieldInterface.h"

#include"AirElemental.h"
#include"DarkElemental.h"
#include"LightElemental.h"
#include"EarthElemental.h"
#include"WaterElemental.h"
#include"FireElemental.h"

#include<deque>
#include "Volcano.h"

VoidField::VoidField()
{
	m_name = "Void field";
	m_field_type = 0;
}

VoidField::VoidField(int fields_size)
{
	m_name = "Void field";
	m_field_type = 0;
	for (int i = 0; i < fields_size; i++) {
		std::vector<Elemental> elementals_line;
		for (int j = 0; j < fields_size; j++) {
			Elemental elemental;
			elementals_line.push_back(elemental);
		}
		m_elementals.push_back(elementals_line);
	}
}

std::string VoidField::GetName()
{
	return m_name;
}

void VoidField::FieldOptions(std::string players_name,std::deque<int>& gci)
{
	if (m_field_type == 0) {
		FieldInterface::VoidField();
		return;
	}
	int command;
	do {
		std::vector<std::vector<std::string>> field;
		for (int i = 0; i < m_elementals.size(); i++) {
			std::vector<std::string> field_line;
			for (int j = 0; j < m_elementals.size(); j++) {
				field_line.push_back(m_elementals[i][j].GetName());
			}
			field.push_back(field_line);
		}
		command = FieldInterface::GetCommand(players_name, field);
		Elemental new_elemental;
		int x, y;
		switch (command)
		{
		case 0:
			break;
		case 1:
		{
			x = FieldInterface::GetFirstCoordinate(m_elementals.size());
			y = FieldInterface::GetSecondCoordinate(m_elementals.size());
			bool elemental_sacrefice = m_elementals[x][y].ElementalOptions(players_name, gci);
			if (elemental_sacrefice == true) {
				Elemental e;
				m_elementals[x][y] = e;
			}
			if (gci.empty() == 0)
				return;
			break;
		}
		case 2:
			x = FieldInterface::GetFirstCoordinate(m_elementals.size());
			y = FieldInterface::GetSecondCoordinate(m_elementals.size());
			if (m_elementals[x][y].GetName() == "Void")
				MakeElemental(new_elemental, players_name, gci);
			else
				FieldInterface::ImposibleAction();
			m_elementals[x][y] = new_elemental;
			if (gci.empty() == 0)
				return;
			break;
		}
	} while (command != 0);
	return;
}

VoidField& VoidField::operator=(const VoidField& void_field)
{
	m_field_type = void_field.m_field_type;
	m_name = void_field.m_name;

	return*this;
}

void VoidField::MakeElemental(Elemental& new_elemental,std::string players_name, std::deque<int>& gci)
{
	int type = FieldInterface::GetElementalType(players_name);
	switch (type)
	{
	case 0:
		return;
	case 1:
	{
		DarkElemental d(players_name);
		gci.push_back(0);
		gci.push_back(1);
		gci.push_back(1);
		gci.push_back(5);
		new_elemental = d;
		return;
	}
	case 2:
	{
		LightElemental l(players_name);
		gci.push_back(0);
		gci.push_back(1);
		gci.push_back(2);
		gci.push_back(5);
		new_elemental = l;
		return;
	}
	case 3:
	{
		WaterElemental w(players_name);
		gci.push_back(0);
		gci.push_back(1);
		gci.push_back(6);
		gci.push_back(5);
		new_elemental = w;
		return;
	}
	case 4:
	{
		FireElemental f(players_name);
		gci.push_back(0);
		gci.push_back(1);
		gci.push_back(5);
		gci.push_back(5);
		new_elemental = f;
		return;
	}
	case 5:
	{
		EarthElemental e(players_name);
		gci.push_back(0);
		gci.push_back(1);
		gci.push_back(4);
		gci.push_back(5);
		new_elemental = e;
		return;
	}
	case 6:
	{
		AirElemental a(players_name);
		gci.push_back(0);
		gci.push_back(1);
		gci.push_back(3);
		gci.push_back(5);
		new_elemental = a;
		return;
	}
	}
}

void VoidField::EndOfTurn(std::deque<int>& gci,std::string playes_name)
{
	for (int i = 0; i < m_elementals.size(); i++) {
		for (int j = 0; j < m_elementals.size(); j++) {
			if ((m_elementals[i][j].GetName() != "Void")&&(m_elementals[i][j].GetPlayersName()==playes_name))
				m_elementals[i][j].GiveManaToPlayers(gci);
		}
	}
	if (GetName() == "Volcano") {
		auto field = dynamic_cast<Volcano*>(this);
		field->FieldFeature();
	}
}

void VoidField::ElementalAction(std::deque<int>& gci,std::string players_name)
{
	std::vector<std::vector<std::string>> field;
	for (int i = 0; i < m_elementals.size(); i++) {
		std::vector<std::string> field_line;
		for (int j = 0; j < m_elementals.size(); j++) {
			field_line.push_back(m_elementals[i][j].GetName());
		}
		field.push_back(field_line);
	}
	int x, y;
	switch (gci[0])
	{
	case 1:
		gci.pop_front();
		FieldInterface::OutputMap(players_name,field);
		x = FieldInterface::GetFirstCoordinate(m_elementals.size());
		y = FieldInterface::GetSecondCoordinate(m_elementals.size());
		m_elementals[x][y].TakeAlienAction(gci);
		return;
	case 2:
		gci.pop_front();
		FieldInterface::OutputMap(players_name, field);
		x = FieldInterface::GetFirstCoordinate(m_elementals.size());
		y = FieldInterface::GetSecondCoordinate(m_elementals.size());
		for (int i = 0; i < m_elementals.size(); i++) {
			m_elementals[i][y].TakeAlienAction(gci);
		}
		for (int i = 0; i < m_elementals.size(); i++) {
			if(y!=i)
				m_elementals[x][i].TakeAlienAction(gci);
		}
		return;
	case 3:
		gci.pop_front();
		for (int i = 0; i < m_elementals.size(); i++) {
			for (int j = 0; j < m_elementals.size(); j++) {
				m_elementals[i][j].TakeAlienAction(gci);
			}
		}
	}
}

void VoidField::FieldFeature()
{

}
