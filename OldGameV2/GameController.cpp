#include "GameController.h"
#include"StartMenuInterface.h"

GameController::GameController()
{
	StartMenu();
}

void GameController::StartMenu()
{
	int mode{StartMenuInterface::ChooseMode()};
	if (mode == 1)
		ChessMode();
	else
		SandboxMode();
}

//� ���� ������� �������� ��������� ���������, ������ ���, � ����� ���������� ������� ���� � ������� ���. �������
void GameController::ChessMode()
{
	//������ ��������� ���������� �� ���������� �����, � ���������� ��� ��� �� �����������
	{
		int game_board_size = StartMenuInterface::GetGameBoardSize();//������� ��������� ���� ��������
		int field_size = StartMenuInterface::GetFieldSize();//����������� ���� �����
		ChessBoard tmp_chhessboard(game_board_size,field_size);
		m_chessboard = tmp_chhessboard;

		int num_of_players = StartMenuInterface::GetNumberOfPlayers();//���������� �������
		//���������� ������� �������
		for (int i = 0; i < num_of_players; i++) {
			Player player(i);
			m_players.push_back(player);
		}
	}
	GameCycle();
}

void GameController::SandboxMode()
{

}

void GameController::GameCycle()
{
	std::deque<int> game_controller_instructions;
	std::vector<int> losed_players;//������ �������� ����������� �������, �������
	//����� �������������� ��� �������� ������� � ������� �������
	while (m_players.size() != 1) {
		for (int i = 0; i < m_players.size(); i++)
			if ((m_players[i].GetActionPoints()>0) || 
			(m_players[i].GetTotalNumberOfElements()>0))//�������� �� ����������� ���������� ����
				losed_players.push_back(i);

		for (int i = 0; i < m_players.size(); i++) {
			while(true) {
				m_players[i].MyTurn(m_chessboard,game_controller_instructions);//��� �������
				if (game_controller_instructions.empty() == 1)
					break;
				else
					DoInstruction(game_controller_instructions,m_players[i]);
			}
		}

		for (int i = 0; i < m_players.size(); i++) {
			m_chessboard.EndOfTurn(game_controller_instructions, m_players[i].GetName());
			if (game_controller_instructions.empty() == 1)
				break;
			else
				DoInstruction(game_controller_instructions, m_players[i]);
			
		}
	}
}

void GameController::DoInstruction(std::deque<int>& game_controller_instruction,Player& player)
{
	while (game_controller_instruction.empty() == 0) {
		switch (game_controller_instruction[0])
		{
		case 0:
		{
			game_controller_instruction.pop_front();
			player.PayForAction(game_controller_instruction);
			break;
		}
		case 1:
		{
			game_controller_instruction.pop_front();
			player.TakeMana(game_controller_instruction);
			break;
		}
		case 2:
		{
			game_controller_instruction.pop_front();
			m_chessboard.ElementalsAction(game_controller_instruction, player.GetName());
			break;
		}
		}
	}
}
