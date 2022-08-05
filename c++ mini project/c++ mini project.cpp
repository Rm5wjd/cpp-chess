#include <iostream>
#include "Board.h"
#include "ChessPiece.h"
#include "Util.h"

int main()
{
	SwitchingConsoleCursor(true, 100);
	bool blackTurn = false;
	while (true)
	{		
		// 1. 렌더링

		SetColor(15, 0);
		ChessPiece::_board->Display();
		
		// 2. 커맨드 입력
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

