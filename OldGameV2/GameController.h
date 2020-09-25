#pragma once

#include<vector>
#include<deque>

#include"Player.h"
#include"ChessBoard.h"

class GameController {
private:
	std::vector<Player> m_players;//массив игроков
	ChessBoard m_chessboard; //Карта содержащая поля с элементалями
public:
	GameController();//начинаю игру в стартовом меню
	void StartMenu();//вывожу стартовое меню узнавая режим игры
	void ChessMode();//основной режим
	void SandboxMode();//режим теста
	void GameCycle();//Игровой цикл в основном режиме
	void DoInstruction(std::deque<int>&,Player& player);//выполнение сложных инструкций
};