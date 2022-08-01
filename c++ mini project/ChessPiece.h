#pragma once
#ifndef __CHESS_PIECE_H__
#define __CHESS_PIECE_H__
#include "Define.h"
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <vector>

class Board;
class ChessPiece
{
private:
	Piecetype type; // 자신만의 타입(기물모양)
	Team team; // 0:흑 1:백
	
public:
	// 생성자
	ChessPiece();
	ChessPiece(Piecetype type, Team team);
	Piecetype GetType() const;
	Team GetTeam() const;
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
	static Board* _board;
	// 소멸자
	~ChessPiece() {};

};

class Pawn : public ChessPiece
{
private:
	bool firstMove;
	//bool isMove;
	//bool isrightAtk;
	//bool isleftAtk;
public:
	Pawn();
	Pawn(Piecetype type, Team team, bool firstMove);
	void firstMoveOff();
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
};

class Rock : public ChessPiece
{
private:
public:
	Rock();
	Rock(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
};

class Bishop : public ChessPiece
{
private:
public:
	Bishop();
	Bishop(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
};

class Knight : public ChessPiece
{
private:
public:
	Knight();
	Knight(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
};

class Queen : public ChessPiece
{
private:
public:
	Queen();
	Queen(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
};

class King : public ChessPiece
{
private:
public:
	King();
	King(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y, std::vector<COORD>& possiblePos);
	virtual void Move(int x, int y, bool& cancle);
};
#endif