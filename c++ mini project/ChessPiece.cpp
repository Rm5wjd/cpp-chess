#include "ChessPiece.h"
#include "Board.h"


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

Pawn::Pawn()
	:ChessPiece(), firstMove(false), isAtk(false)
{

}
Pawn::Pawn(Piecetype type, Team team, bool atkFlag)
	:ChessPiece(type, team), firstMove(atkFlag), isAtk(false)
{

}

void Pawn::firstMoveOff()
{
	firstMove = false;
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

				if (destX < x || destX > x || destY > y + Y_SHIFT * 2 || destY < y)
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
			Board::gotoxy(x, y + Y_SHIFT);
			std::cout << "O";

			while (true)
			{
				int destX, destY;
				COORD destPos = _board->GetCommand(x, y);
				destX = destPos.X;
				destY = destPos.Y;

				if (destX < x || destX > x || destY > y + Y_SHIFT || destY < y)
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

				if (destX < x || destX > x || destY < y - Y_SHIFT * 2 || destY > y)
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
			Board::gotoxy(x, y - Y_SHIFT);
			std::cout << "O";

			while (true)
			{
				int destX, destY;
				COORD destPos = _board->GetCommand(x, y);
				destX = destPos.X;
				destY = destPos.Y;

				if (destX < x || destX > x || destY < y - Y_SHIFT || destY > y)
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

Rock::Rock()
	:ChessPiece()
{

}

Rock::Rock(Piecetype type, Team team)
	:ChessPiece(type, team)
{

}

void Rock::Move(int x, int y)
{

}

Bishop::Bishop()
	:ChessPiece()
{

}

Bishop::Bishop(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void Bishop::Move(int x, int y)
{

}

Knight::Knight()
	:ChessPiece()
{

}

Knight::Knight(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void Knight::Move(int x, int y)
{

}

King::King()
	:ChessPiece()
{

}

King::King(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void King::Move(int x, int y)
{

}

Queen::Queen()
	:ChessPiece()
{

}

Queen::Queen(Piecetype type, Team team)
	: ChessPiece(type, team)
{

}

void Queen::Move(int x, int y)
{

}