#include "ChessBoard.h"

#include "Volcano.h"
#include "ArtificialTerrain.h"
#include "Cloud.h"
#include "Desert.h"
#include "Mountain.h"
#include "Ocean.h"
#include "Space.h"

ChessBoard::ChessBoard()
{

}

ChessBoard::ChessBoard(int game_board_size, int field_size)
{
	for (int i = 0; i < game_board_size; i++) {
		std::vector<VoidField> fields_line;
		for (int j = 0; j < game_board_size; j++) {
			VoidField field(field_size);
			fields_line.push_back(field);
		}
		m_fields.push_back(fields_line);
	}
}

void ChessBoard::MapOptions(std::string players_name,std::deque<int>& gci)
{
	int command;
	do {
		std::vector<std::vector<std::string>> map;
		for (int i = 0; i < m_fields.size(); i++) {
			std::vector<std::string> map_line;
			for (int j = 0; j < m_fields.size(); j++) {
				map_line.push_back(m_fields[i][j].GetName());
			}
			map.push_back(map_line);
		}
		command = ChessBoardInterface::GetCommand(players_name, map);
		int x, y;
		switch (command)
		{
		case 0:
			break;
		case 1:
			x = ChessBoardInterface::GetFirstCoordinate(m_fields.size());
			y = ChessBoardInterface::GetSecondCoordinate(m_fields.size());
			m_fields[x][y].FieldOptions(players_name,gci);
			if (gci.empty() == 0)
				return;
			break;
		case 2:
			x = ChessBoardInterface::GetFirstCoordinate(m_fields.size());
			y = ChessBoardInterface::GetSecondCoordinate(m_fields.size());
			VoidField new_field;
			MakeField(new_field,players_name,gci);
			if (new_field.GetName() == "Void field")
				break;
			m_fields[x][y] = new_field;
			if (gci.empty() == 0)
				return;
			break;
		}
	} while (command != 0);
	return;
}

void ChessBoard::MakeField(VoidField& new_field,std::string players_name,std::deque<int>& gci)
{
	int choice = ChessBoardInterface::GetFieldType(players_name);
	switch(choice)
	{
		case 0:
			return;
		case 1:
		{
			ArtificialTerrain a;
			gci.push_back(0);
			gci.push_back(1);
			gci.push_back(0);
			gci.push_back(0);
			new_field = a;
			return;
		}
		case 2:
		{
			Cloud c;
			gci.push_back(0);
			gci.push_back(1);
			gci.push_back(3);
			gci.push_back(10);
			new_field = c;
			return;
		}
		case 3:
		{
			Desert d;
			gci.push_back(0);
			gci.push_back(2);
			gci.push_back(3);
			gci.push_back(5);
			gci.push_back(5);
			gci.push_back(5);
			new_field = d;
			return;
		}
		case 4:
		{
			Mountain m;
			gci.push_back(0);
			gci.push_back(1);
			gci.push_back(4);
			gci.push_back(10);
			new_field = m;
			return;
		}
		case 5:
		{
			Ocean o;
			gci.push_back(0);
			gci.push_back(1);
			gci.push_back(6);
			gci.push_back(10);
			new_field = o;
			return;
		}
		case 6:
		{
			Space s;
			gci.push_back(0);
			gci.push_back(2);
			gci.push_back(1);
			gci.push_back(5);
			gci.push_back(2);
			gci.push_back(5);
			new_field = s;
			return;
		}
		case 7:
		{
			Volcano v;
			gci.push_back(0);
			gci.push_back(2);
			gci.push_back(4);
			gci.push_back(5);
			gci.push_back(5);
			gci.push_back(5);
			new_field = v;
			return;
		}
	}
}

void ChessBoard::EndOfTurn(std::deque<int>& gci,std::string players_name)
{
	for (int i = 0; i < m_fields.size(); i++) {
		for (int j = 0; j < m_fields.size(); j++) {
			if (m_fields[i][j].GetName() != "Void field")
				m_fields[i][j].EndOfTurn(gci,players_name);
		}
	}
}

void ChessBoard::ElementalsAction(std::deque<int>& gci, std::string players_name)
{
	std::vector<std::vector<std::string>> map;
	for (int i = 0; i < m_fields.size(); i++) {
		std::vector<std::string> map_line;
		for (int j = 0; j < m_fields.size(); j++) {
			map_line.push_back(m_fields[i][j].GetName());
		}
		map.push_back(map_line);
	}
	ChessBoardInterface::ReturnMap(players_name,map);
	int x = ChessBoardInterface::GetFirstCoordinate(m_fields.size());
	int y = ChessBoardInterface::GetSecondCoordinate(m_fields.size());
	m_fields[x][y].ElementalAction(gci,players_name);
}
