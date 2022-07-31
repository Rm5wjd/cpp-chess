#include <iostream>
#include "Board.h"
#include "ChessPiece.h"

int main()
{
	// 1. 판 생성 ( 초기화)
	//Board newBoard;
	//newBoard.SwitchingConsoleCursor(true, 100);

	ChessPiece::_board->SwitchingConsoleCursor(true, 100);
	//Board::setBgColor(11);
	bool blackTurn = false;
	while (true)
	{
		
		// 3. 렌더링
		//newBoard.Display();
		ChessPiece::_board->Display();
		
		// 2. 커맨드 입력
		//newBoard.GetCommand();
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

