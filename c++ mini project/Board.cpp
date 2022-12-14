#include "Board.h"
#include "ChessPiece.h"
#include "Util.h"

Board::Board() : board{nullptr, }
{
	// black
	board[0][0] = new Rock(Piecetype::ROCK, Team::BLACK);
	board[0][1] = new Knight(Piecetype::KNIGHT, Team::BLACK);
	board[0][2] = new Bishop(Piecetype::BISHOP, Team::BLACK);
	board[0][3] = new King(Piecetype::KING, Team::BLACK);
	//blackKing = board[0][3];
	board[0][4] = new Queen(Piecetype::QUEEN, Team::BLACK);
	board[0][5] = new Bishop(Piecetype::BISHOP, Team::BLACK);
	board[0][6] = new Knight(Piecetype::KNIGHT, Team::BLACK);
	board[0][7] = new Rock(Piecetype::ROCK, Team::BLACK);

	board[1][0] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][1] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][2] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][3] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][4] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][5] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][6] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][7] = new Pawn(Piecetype::PAWN, Team::BLACK, true);

	// white
	board[7][0] = new Rock(Piecetype::ROCK, Team::WHITE);
	board[7][1] = new Knight(Piecetype::KNIGHT, Team::WHITE);
	board[7][2] = new Bishop(Piecetype::BISHOP, Team::WHITE);
	board[7][3] = new King(Piecetype::KING, Team::WHITE);
	//whiteKing = board[7][3];
	board[7][4] = new Queen(Piecetype::QUEEN, Team::WHITE);
	board[7][5] = new Bishop(Piecetype::BISHOP, Team::WHITE);
	board[7][6] = new Knight(Piecetype::KNIGHT, Team::WHITE);
	board[7][7] = new Rock(Piecetype::ROCK, Team::WHITE);

	board[6][0] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][1] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][2] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][3] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][4] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][5] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][6] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][7] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	
}

void Board::Display()
{
	if (KingIsDie())
	{
		Sleep(2000);
		exit(0);
	}
	// ?????? ????
	gotoxy(37, 3);
	std::cout << "Select piece : SPACEBAR";
	gotoxy(37, 5);
	std::cout << "Move piece : SPACEBAR";
	gotoxy(37, 7);
	std::cout << "Game Exit : ESC";
	gotoxy(37, 9);
	std::cout << "Game Reset : R";

	//????
	int num = 1;
	for (int y = START_Y; y < START_Y + (Y_SHIFT * 8); y += Y_SHIFT)
	{
		int x = START_X - 3;
		gotoxy(x, y);
		std::cout << num++;
	}

	char alphabet = 65;
	for (int x = START_X; x < START_X + (X_SHIFT * 8); x += X_SHIFT)
	{
		int y = START_Y - 2;
		gotoxy(x, y);
		std::cout << alphabet++;
	}


	for (int x = START_X; x < START_X + (X_SHIFT * 8); x += X_SHIFT)
	{
		for (int y = START_Y - 1; y < (START_Y - 1) + (Y_SHIFT * 9); y += Y_SHIFT)
		{
			gotoxy(x, y);
			std::cout << "--";
		}
	}

	for (int x = START_X - 2; x < (START_X - 2) + (X_SHIFT * 9); x += X_SHIFT)
	{
		for (int y = START_Y; y < START_Y + (Y_SHIFT * 8); y += Y_SHIFT)
		{
			gotoxy(x, y);
			std::cout << "??";
		}
	}

	int i = 0;
	int j = 0;
	for (int x = START_X; x < START_X + (X_SHIFT * 8); x += X_SHIFT)
	{
		for (int y = START_Y; y < START_Y + (Y_SHIFT * 8); y += Y_SHIFT)
		{
			gotoxy(x, y);
			i = (y - START_Y) / Y_SHIFT;
			j = (x - START_X) / X_SHIFT;

			if (board[i][j] != nullptr)
			{
				Render(board[i][j]->GetType(), board[i][j]->GetTeam());
			}

			/*else
			{
				SetColor(4, 0);
				std::cout << "Np";
			}*/
		}
	}


}

void Board::Render(Piecetype type, Team team)
{
	if (team == Team::BLACK)
	{
		SetColor(9, 0);
	}

	else
	{
		SetColor(15, 0);
	}

	switch (type)
	{
	case Piecetype::PAWN:
		std::cout << "Pn";
		break;
	case Piecetype::KNIGHT:
		std::cout << "Kn";
		break;
	case Piecetype::BISHOP:
		std::cout << "Bi";
		break;
	case Piecetype::KING:
		std::cout << "Ki";
		break;
	case Piecetype::QUEEN:
		std::cout << "Qu";
		break;
	case Piecetype::ROCK:
		std::cout << "Ro";
		break;
	default:
		break;
	}
}

void Board::GetCommand(Team team)
{
	int x, y;
	bool cancle = false;

	gotoxy(4, 22);
	if (team == Team::BLACK)
	{
		std::cout << "turn: Black";
		x = START_X, y = START_Y;
	}

	else
	{
		std::cout << "turn: White";
		x = START_X, y = START_Y + Y_SHIFT * 6;
	}

	char inputCommand = 0;
	while (true)
	{
		gotoxy(x, y);
		if (_kbhit())
		{
			inputCommand = _getch();
			if (inputCommand == 224)
			{
				inputCommand = _getch();
			}

			switch (inputCommand)
			{
			case UP:
				y -= Y_SHIFT;
				if (y < START_Y)
				{
					y = START_Y;
				}
				break;

			case DOWN:
				y += Y_SHIFT;
				if (y > END_Y)
				{
					y = END_Y;
				}
				break;

			case LEFT:
				x -= X_SHIFT;
				if (x < START_X)
				{
					x = START_X;
				}
				break;

			case RIGHT:
				x += X_SHIFT;
				if (x > END_X)
				{
					x = END_X;
				}
				break;

			case SPACEBAR:
				// ?????? ?? ???? ????, ????, ???? ????
				if (CoordConvert(getxy().X, getxy().Y) == nullptr)
				{
					gotoxy(4, 20);
					std::cout << "have no piece, Choose again";
					break;
				}
				else
				{
					if (CoordConvert(getxy().X, getxy().Y)->GetTeam() != team)
					{
						gotoxy(4, 20);
						std::cout << "It's not your turn";
						break;
					}

					CoordConvert(getxy().X, getxy().Y)->Move(getxy().X, getxy().Y, cancle);
					if (cancle)
					{
						gotoxy(4, 20);
						std::cout << "don't move, Choose piece again";
						cancle = false;
						break;
					}
					system("cls");
					return;
				}
			case ESC:
				system("cls");
				std::cout << "EXIT THE GAME ...";
				Sleep(1000);
				exit(0);
			case 'R':
			case 'r':
				Restart();
				system("cls");
				std::cout << "GAME RESET ...";
				Sleep(1000);
				system("cls");
				return;

			default:
				break;
			}

		}
		Sleep(50);
		//system("cls");
	}
}

COORD Board::GetCommand(int x, int y)
{
	char inputCommand = 0;
	while (true)
	{
		gotoxy(x, y);
		if (_kbhit())
		{
			inputCommand = _getch();
			if (inputCommand == 224)
			{
				inputCommand = _getch();
			}

			switch (inputCommand)
			{
			case UP:
				y -= Y_SHIFT;
				if (y < START_Y)
				{
					y = START_Y;
				}
				break;

			case DOWN:
				y += Y_SHIFT;
				if (y > END_Y)
				{
					y = END_Y;
				}
				break;

			case LEFT:
				x -= X_SHIFT;
				if (x < START_X)
				{
					x = START_X;
				}
				break;

			case RIGHT:
				x += X_SHIFT;
				if (x > END_X)
				{
					x = END_X;
				}
				break;
				
			case SPACEBAR:
				return getxy();

			case ESC:
				system("cls");
				std::cout << "EXIT THE GAME ...";
				Sleep(1000);
				exit(0);
			default:
				break;
			}
		}
		Sleep(50);
		//system("cls");
	}
}

ChessPiece* Board::CoordConvert(int x, int y)
{
	return board[(y - START_Y) / Y_SHIFT][(x - START_X) / X_SHIFT];
}

void Board::MovePiece(int startX, int startY, int destX, int destY)
{
	if (board[(startY - START_Y) / Y_SHIFT][(startX - START_X) / X_SHIFT] == nullptr)
	{
		std::cout << "have no piece";
		return;
	}

	// nullptr?? ?????? ???? ????
	Piecetype type = board[(startY - START_Y) / Y_SHIFT][(startX - START_X) / X_SHIFT]->GetType();

	if (board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] == nullptr)
	{
		switch (type)
		{
		case Piecetype::PAWN:
			board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = new Pawn();
			break;
		case Piecetype::ROCK:
			board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = new Rock();
			break;
		case Piecetype::KNIGHT:
			board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = new Knight();
			break;
		case Piecetype::BISHOP:
			board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = new Bishop();
			break;
		case Piecetype::QUEEN:
			board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = new Queen();
			break;
		case Piecetype::KING:
			board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = new King();
			break;
		default:
			break;
		}
		
		board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = board[(startY - START_Y) / Y_SHIFT][(startX - START_X) / X_SHIFT];
		board[(startY - START_Y) / Y_SHIFT][(startX - START_X) / X_SHIFT] = nullptr;
	}

	else
	{
		delete board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT];
		board[(destY - START_Y) / Y_SHIFT][(destX - START_X) / X_SHIFT] = board[(startY - START_Y) / Y_SHIFT][(startX - START_X) / X_SHIFT];
		board[(startY - START_Y) / Y_SHIFT][(startX - START_X) / X_SHIFT] = nullptr;
	}
	//system("cls");
}

bool Board::KingIsDie()
{
	int blackCount = 0;
	int whiteCount = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->GetType() == Piecetype::KING)
				{
					if (board[i][j]->GetTeam() == Team::WHITE)
					{
						whiteCount++;
					}

					else
					{
						blackCount++;
					}
				}
			}
		}
	}

	if (blackCount == 0)
	{
		std::cout << "White Win !!!";
		return true;
	}

	else if (whiteCount == 0)
	{
		std::cout << "Black Win !!!";
		return true;
	}

	else
	{
		return false;
	}
}

void Board::Restart()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete board[i][j];
			board[i][j] = nullptr;
		}
	}

	// black
	board[0][0] = new Rock(Piecetype::ROCK, Team::BLACK);
	board[0][1] = new Knight(Piecetype::KNIGHT, Team::BLACK);
	board[0][2] = new Bishop(Piecetype::BISHOP, Team::BLACK);
	board[0][3] = new King(Piecetype::KING, Team::BLACK);
	board[0][4] = new Queen(Piecetype::QUEEN, Team::BLACK);
	board[0][5] = new Bishop(Piecetype::BISHOP, Team::BLACK);
	board[0][6] = new Knight(Piecetype::KNIGHT, Team::BLACK);
	board[0][7] = new Rock(Piecetype::ROCK, Team::BLACK);

	board[1][0] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][1] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][2] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][3] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][4] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][5] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][6] = new Pawn(Piecetype::PAWN, Team::BLACK, true);
	board[1][7] = new Pawn(Piecetype::PAWN, Team::BLACK, true);

	// white
	board[7][0] = new Rock(Piecetype::ROCK, Team::WHITE);
	board[7][1] = new Knight(Piecetype::KNIGHT, Team::WHITE);
	board[7][2] = new Bishop(Piecetype::BISHOP, Team::WHITE);
	board[7][3] = new King(Piecetype::KING, Team::WHITE);
	board[7][4] = new Queen(Piecetype::QUEEN, Team::WHITE);
	board[7][5] = new Bishop(Piecetype::BISHOP, Team::WHITE);
	board[7][6] = new Knight(Piecetype::KNIGHT, Team::WHITE);
	board[7][7] = new Rock(Piecetype::ROCK, Team::WHITE);

	board[6][0] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][1] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][2] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][3] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][4] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][5] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][6] = new Pawn(Piecetype::PAWN, Team::WHITE, true);
	board[6][7] = new Pawn(Piecetype::PAWN, Team::WHITE, true);

}

Board::~Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
			}
		}
	}
}