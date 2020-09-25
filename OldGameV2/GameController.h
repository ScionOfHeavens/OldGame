#pragma once

#include<vector>
#include<deque>

#include"Player.h"
#include"ChessBoard.h"

class GameController {
private:
	std::vector<Player> m_players;//������ �������
	ChessBoard m_chessboard; //����� ���������� ���� � ������������
public:
	GameController();//������� ���� � ��������� ����
	void StartMenu();//������ ��������� ���� ������� ����� ����
	void ChessMode();//�������� �����
	void SandboxMode();//����� �����
	void GameCycle();//������� ���� � �������� ������
	void DoInstruction(std::deque<int>&,Player& player);//���������� ������� ����������
};