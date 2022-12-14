#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__
#define board_size 8
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include "Define.h"

#define X_SHIFT 4
#define Y_SHIFT 2

#define START_X 4
#define START_Y 3
#define END_X START_X + (X_SHIFT * 7)
#define END_Y START_Y + (Y_SHIFT * 7)

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESC 27
#define SPACEBAR 32

class ChessPiece;
class Board
{
private:
	ChessPiece* board[8][8];
public:
	Board();
	void Display();
	void Render(Piecetype type, Team team);
	ChessPiece* CoordConvert(int x, int y);
	void GetCommand(Team team);
	COORD GetCommand(int x, int y);
	void MovePiece(int startX, int startY, int destX, int destY);
	bool KingIsDie();
	void Restart();
	~Board();
};


#endif