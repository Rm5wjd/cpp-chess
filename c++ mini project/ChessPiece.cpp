#include "ChessPiece.h"
#include "Board.h"

#pragma region "베이스클래스"
Board* ChessPiece::_board = new Board();

ChessPiece::ChessPiece()
	:type(Piecetype::NULLPTR), team(Team::BLACK)
{
	
}

ChessPiece::ChessPiece(Piecetype type, Team team)
{
	this->type = type;
	this->team = team;
}

void ChessPiece::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{
	std::cout << "virtual funtion";
}

void ChessPiece::Move(int x, int y, bool& cancle)
{
	std::cout << "vritual funtion";
}

Piecetype ChessPiece::GetType() const
{
	if (this == nullptr)
	{
		std::cout << "nullptr access";
		return Piecetype::NULLPTR;
	}

	return type;
}

Team ChessPiece::GetTeam() const
{
	if (this == nullptr)
	{
		std::cout << "nullptr access";
		return Team::NULLPTR;
	}

	return team;
}

#pragma endregion

#pragma region "Pawn Class"
Pawn::Pawn()
	:ChessPiece(), firstMove(false)
{

}
Pawn::Pawn(Piecetype type, Team team, bool atkFlag)
	:ChessPiece(type, team), firstMove(atkFlag)
{

}

void Pawn::firstMoveOff()
{
	firstMove = false;
}

void Pawn::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{
	if (GetTeam() == Team::BLACK)
	{
		if (_board->CoordConvert(x, y + Y_SHIFT) == nullptr)
		{
			Board::gotoxy(x, y + Y_SHIFT);
			possiblePos.push_back(Board::getxy());
			std::cout << "O";

			if (firstMove)
			{
				if (_board->CoordConvert(x, y + Y_SHIFT * 2) == nullptr)
				{
					Board::gotoxy(x, y + Y_SHIFT * 2);
					possiblePos.push_back(Board::getxy());
					std::cout << "O";
					firstMove = false;
				}
			}
		}

		if (_board->CoordConvert(x - X_SHIFT, y + Y_SHIFT) != nullptr && 
			_board->CoordConvert(x - X_SHIFT, y + Y_SHIFT)->GetTeam() == Team::WHITE)
		{
			Board::gotoxy(x - X_SHIFT, y + Y_SHIFT);
			possiblePos.push_back(Board::getxy());
			std::cout << "X";
		}

		if (_board->CoordConvert(x + X_SHIFT, y + Y_SHIFT) != nullptr &&
			_board->CoordConvert(x + X_SHIFT, y + Y_SHIFT)->GetTeam() == Team::WHITE)
		{
			Board::gotoxy(x + X_SHIFT, y + Y_SHIFT);
			possiblePos.push_back(Board::getxy());
			std::cout << "X";
		}
	}

	else
	{
		if (_board->CoordConvert(x, y - Y_SHIFT) == nullptr)
		{
			Board::gotoxy(x, y - Y_SHIFT);
			possiblePos.push_back(Board::getxy());
			std::cout << "O";

			if (firstMove)
			{
				if (_board->CoordConvert(x, y - Y_SHIFT * 2) == nullptr)
				{
					Board::gotoxy(x, y - Y_SHIFT * 2);
					possiblePos.push_back(Board::getxy());
					std::cout << "O";
					firstMove = false;
				}
			}
		}

		if (_board->CoordConvert(x - X_SHIFT, y - Y_SHIFT) != nullptr &&
			_board->CoordConvert(x - X_SHIFT, y - Y_SHIFT)->GetTeam() == Team::BLACK)
		{
			Board::gotoxy(x - X_SHIFT, y - Y_SHIFT);
			possiblePos.push_back(Board::getxy());
			std::cout << "X";
		}

		if (_board->CoordConvert(x + X_SHIFT, y - Y_SHIFT) != nullptr &&
			_board->CoordConvert(x + X_SHIFT, y - Y_SHIFT)->GetTeam() == Team::BLACK)
		{
			Board::gotoxy(x + X_SHIFT, y - Y_SHIFT);
			possiblePos.push_back(Board::getxy());
			std::cout << "X";
		}
	}
}

void Pawn::Move(int x, int y, bool& cancle)
{
	std::vector<COORD> possiblePos;
	Pawn::CheckPossibleMovement(x, y, possiblePos);

	if (possiblePos.size() == 0)
	{
		cancle = true;
		return;
	}
		
	while (true)
	{
		int destX, destY;
		COORD destPos = _board->GetCommand(x, y);
		destX = destPos.X;
		destY = destPos.Y;

		for (int i = 0; i < possiblePos.size(); i++)
		{
			if (destX == possiblePos[i].X && destY == possiblePos[i].Y)
			{
				_board->MovePiece(x, y, destX, destY);
				_board->gotoxy(destY, destX);
				return;
			}
		}
	}
}

#pragma endregion

#pragma region "Rock Class"
Rock::Rock()
	:ChessPiece()
{

}

Rock::Rock(Piecetype type, Team team)
	:ChessPiece(type, team)
{

}

void Rock::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{
	COORD direction[4] = { COORD{0, -Y_SHIFT}, COORD{0, Y_SHIFT}, COORD{-X_SHIFT, 0}, COORD{X_SHIFT, 0} }; // 상하좌우

	if (GetTeam() == Team::BLACK)
	{		
		for (int i = 0; i < 4; i++)
		{
			int count = 1;
			while(true)
			{
				if (x + direction[i].X * count < START_X || x + direction[i].X * count > END_X ||
					y + direction[i].Y * count < START_Y || y + direction[i].Y * count > END_Y)
				{
					break;
				}


				if (_board->CoordConvert(x + direction[i].X * count, y + direction[i].Y * count) == nullptr)
				{
					Board::gotoxy(x + direction[i].X * count, y + direction[i].Y * count);
					possiblePos.push_back(Board::getxy());
					std::cout << "O";
				}

				else if (_board->CoordConvert(x + direction[i].X * count, y + direction[i].Y * count) != nullptr && _board->CoordConvert(x + direction[i].X * count, y + direction[i].Y * count)->GetTeam() == Team::WHITE)
				{
					Board::gotoxy(x + direction[i].X * count, y + direction[i].Y * count);
					possiblePos.push_back(Board::getxy());
					std::cout << "X";
					break;
				}

				else
				{
					break;
				}
				count++;
			}
		}
	}

	else
	{
		for (int i = 0; i < 4; i++)
		{
			int count = 1;
			while (true)
			{
				if (x + direction[i].X * count < START_X || x + direction[i].X * count > END_X ||
					y + direction[i].Y * count < START_Y || y + direction[i].Y * count > END_Y)
				{
					break;
				}


				if (_board->CoordConvert(x + direction[i].X * count, y + direction[i].Y * count) == nullptr)
				{
					Board::gotoxy(x + direction[i].X * count, y + direction[i].Y * count);
					possiblePos.push_back(Board::getxy());
					std::cout << "O";
				}

				else if (_board->CoordConvert(x + direction[i].X * count, y + direction[i].Y * count) != nullptr &&_board->CoordConvert(x + direction[i].X * count, y + direction[i].Y * count)->GetTeam() == Team::BLACK)
				{
					Board::gotoxy(x + direction[i].X * count, y + direction[i].Y * count);
					possiblePos.push_back(Board::getxy());
					std::cout << "X";
					break;
				}

				else
				{
					break;
				}
				count++;
			}
		}
	}
}

void Rock::Move(int x, int y, bool& cancle)
{
	std::vector<COORD> possiblePos;
	Rock::CheckPossibleMovement(x, y, possiblePos);

	if (possiblePos.size() == 0)
	{
		cancle = true;
		return;
	}

	while (true)
	{
		int destX, destY;
		COORD destPos = _board->GetCommand(x, y);
		destX = destPos.X;
		destY = destPos.Y;

		for (int i = 0; i < possiblePos.size(); i++)
		{
			if (destX == possiblePos[i].X && destY == possiblePos[i].Y)
			{
				_board->MovePiece(x, y, destX, destY);
				_board->gotoxy(destY, destX);
				return;
			}
		}
	}
}
#pragma endregion

#pragma region "Bishop Class"
Bishop::Bishop()
	:ChessPiece()
{

}

Bishop::Bishop(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void Bishop::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{

}

void Bishop::Move(int x, int y, bool& cancle)
{

}
#pragma endregion

#pragma region "Knight Class"
Knight::Knight()
	:ChessPiece()
{

}

Knight::Knight(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void Knight::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{

}

void Knight::Move(int x, int y, bool& cancle)
{

}
#pragma endregion

#pragma region "King Class"
King::King()
	:ChessPiece()
{

}

King::King(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void King::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{

}

void King::Move(int x, int y, bool& cancle)
{

}
#pragma endregion

#pragma region "Queen Class"
Queen::Queen()
	:ChessPiece()
{

}

Queen::Queen(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void Queen::CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos)
{

}

void Queen::Move(int x, int y, bool& cancle)
{

}
#pragma endregion