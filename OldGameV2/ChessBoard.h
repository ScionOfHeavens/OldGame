#pragma once

#include<vector>
#include<string>
#include<deque>

#include"Field.h"
#include"ChessboardInterface.h"

class ChessBoard {
	private:
		std::vector<std::vector<VoidField>> m_fields;
	public:
		ChessBoard();
		ChessBoard(int,int);
		void MapOptions(std::string,std::deque<int>&);
		void MakeField(VoidField&,std::string,std::deque<int>&);
		void EndOfTurn(std::deque<int>&,std::string);
		void ElementalsAction(std::deque<int>&, std::string);
};