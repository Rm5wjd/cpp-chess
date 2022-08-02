#include <iostream>
#include "Board.h"
#include "ChessPiece.h"
#include "Util.h"

int main()
{
	// 1. 판 생성 ( 초기화)
	ChessPiece::_board->SwitchingConsoleCursor(true, 100);
	//Board::setBgColor(11);
	bool blackTurn = false;
	while (true)
	{
		// 조작키 안내
		Board::gotoxy(37, 3);
		std::cout << "Select piece : A";
		Board::gotoxy(37, 4);
		std::cout << "Move piece : A";
		
		// 3. 렌더링
		SetColor(15, 0);
		ChessPiece::_board->Display();
		

		
		// 2. 커맨드 입력
		//SetColor(2, 0);
		if (blackTurn)
		{
			ChessPiece::_board->GetCommand(Team::BLACK);
			blackTurn = false;
		}
		else
		{
			ChessPiece::_board->GetCommand(Team::WHITE);
			blackTurn = true;
		}
	}
}

