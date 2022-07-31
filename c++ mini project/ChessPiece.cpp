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

void ChessPiece::CheckPossibleMovement(int x, int y)
{
	std::cout << "virtual funtion";
}

void ChessPiece::Move(int x, int y)
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
	:ChessPiece(), firstMove(false), isrightAtk(false), isleftAtk(false)
{

}
Pawn::Pawn(Piecetype type, Team team, bool atkFlag)
	:ChessPiece(type, team), firstMove(atkFlag), isrightAtk(false), isleftAtk(false)
{

}

void Pawn::firstMoveOff()
{
	firstMove = false;
}

void Pawn::CheckPossibleMovement(int x, int y)
{
	if (GetTeam() == Team::BLACK)
	{
		if (_board->CoordConvert(x, y + Y_SHIFT) == nullptr)
		{
			Board::gotoxy(x, y + Y_SHIFT);
			std::cout << "O";
		}

		if (_board->CoordConvert(x - X_SHIFT, y + Y_SHIFT) != nullptr)
		{
			Board::gotoxy(x - X_SHIFT, y + Y_SHIFT);
			std::cout << "X";
			isrightAtk = true;
		}

		if (_board->CoordConvert(x + X_SHIFT, y + Y_SHIFT) != nullptr)
		{
			Board::gotoxy(x + X_SHIFT, y + Y_SHIFT);
			std::cout << "X";
			isleftAtk = true;
		}
	}

	else
	{
		if (_board->CoordConvert(x, y - Y_SHIFT) == nullptr)
		{
			Board::gotoxy(x, y - Y_SHIFT);
			std::cout << "O";
		}

		if (_board->CoordConvert(x - X_SHIFT, y - Y_SHIFT) != nullptr)
		{
			Board::gotoxy(x - X_SHIFT, y - Y_SHIFT);
			std::cout << "X";
			isleftAtk = true;
		}

		if (_board->CoordConvert(x + X_SHIFT, y - Y_SHIFT) != nullptr)
		{
			Board::gotoxy(x + X_SHIFT, y - Y_SHIFT);
			std::cout << "X";
			isrightAtk = true;
		}
	}
	
}

void Pawn::Move(int x, int y)
{
	if (GetTeam() == Team::BLACK)
	{
		if (firstMove)
		{
			Board::gotoxy(x, y + Y_SHIFT);
			std::cout << "O";
			Board::gotoxy(x, y + Y_SHIFT * 2);
			std::cout << "O";

			while (true)
			{
				int destX, destY;
				COORD destPos = _board->GetCommand(x, y);
				destX = destPos.X;
				destY = destPos.Y;

				if (destX < x || destX > x || destY > y + Y_SHIFT * 2 || destY < y || (destX == x && destY == y))
				{
					Board::gotoxy(2, 20);
					std::cout << "don't move, Choose again";
					continue;
				}

				else
				{
					firstMove = false;
					_board->MovePiece(x, y, destX, destY);
					_board->gotoxy(destY, destX);
					return;
				}
			}
		}

		else
		{
			Pawn::CheckPossibleMovement(x, y);
			//Board::gotoxy(x, y + Y_SHIFT);
			//std::cout << "O";

			while (true)
			{
				int destX, destY;
				COORD destPos = _board->GetCommand(x, y);
				destX = destPos.X;
				destY = destPos.Y;

				if (isleftAtk && isrightAtk)
				{
					if (destX < x - X_SHIFT || destX > x + X_SHIFT || destY > y + Y_SHIFT || destY < y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						isleftAtk = false;
						isrightAtk = false;
						return;
					}
				}

				else if (isrightAtk)
				{
					if (destX < x - X_SHIFT || destX > x || destY > y + Y_SHIFT || destY < y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						isrightAtk = false;
						return;
					}
				}

				else if (isleftAtk)
				{
					if (destX < x || destX > x + X_SHIFT || destY > y + Y_SHIFT || destY < y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						isleftAtk = false;
						return;
					}
				}

				else
				{
					if (destX < x || destX > x || destY > y + Y_SHIFT || destY < y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						return;
					}
				}
			}
		}
	}

	else
	{
		if (firstMove)
		{
			Board::gotoxy(x, y - Y_SHIFT);
			std::cout << "O";
			Board::gotoxy(x, y - Y_SHIFT * 2);
			std::cout << "O";

			while (true)
			{
				int destX, destY;
				COORD destPos = _board->GetCommand(x, y);
				destX = destPos.X;
				destY = destPos.Y;

				if (destX < x || destX > x || destY < y - Y_SHIFT * 2 || destY > y || (destX == x && destY == y))
				{
					Board::gotoxy(2, 20);
					std::cout << "don't move, Choose again";
					continue;
				}

				else
				{
					firstMove = false;
					_board->MovePiece(x, y, destX, destY);
					_board->gotoxy(destY, destX);
					return;
				}
			}
		}

		else
		{
			Pawn::CheckPossibleMovement(x, y);
			//Board::gotoxy(x, y + Y_SHIFT);
			//std::cout << "O";

			while (true)
			{
				int destX, destY;
				COORD destPos = _board->GetCommand(x, y);
				destX = destPos.X;
				destY = destPos.Y;

				if (isleftAtk && isrightAtk)
				{
					if (destX < x - X_SHIFT || destX > x + X_SHIFT || destY < y - Y_SHIFT || destY > y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						isrightAtk = false;
						isleftAtk = false;
						return;
					}
				}

				else if (isrightAtk)
				{
					if (destX < x || destX > x + X_SHIFT || destY < y - Y_SHIFT || destY > y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						isrightAtk = false;
						return;
					}
				}

				else if (isleftAtk)
				{
					if (destX < x - X_SHIFT || destX > x || destY < y - Y_SHIFT || destY > y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						isleftAtk = false;
						return;
					}
				}

				else
				{
					if (destX < x || destX > x || destY < y - Y_SHIFT || destY > y || (destX == x && destY == y))
					{
						Board::gotoxy(2, 20);
						std::cout << "don't move, Choose agian";
						continue;
					}

					else
					{
						_board->MovePiece(x, y, destX, destY);
						_board->gotoxy(destY, destX);
						return;
					}
				}
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

void Rock::CheckPossibleMovement(int x, int y)
{

}

void Rock::Move(int x, int y)
{

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

void Bishop::CheckPossibleMovement(int x, int y)
{

}

void Bishop::Move(int x, int y)
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

void Knight::CheckPossibleMovement(int x, int y)
{

}

void Knight::Move(int x, int y)
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

void King::CheckPossibleMovement(int x, int y)
{

}

void King::Move(int x, int y)
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

void Queen::CheckPossibleMovement(int x, int y)
{

}

void Queen::Move(int x, int y)
{

}
#pragma endregion