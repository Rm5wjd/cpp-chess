#pragma once
#ifndef __CHESS_PIECE_H__
#define __CHESS_PIECE_H__
#include "Define.h"

class Board;
class ChessPiece
{
private:
	Piecetype type; // �ڽŸ��� Ÿ��(�⹰���)
	Team team; // 0:�� 1:��
	
public:
	// ������
	ChessPiece();
	ChessPiece(Piecetype type, Team team);
	Piecetype GetType() const;
	Team GetTeam() const;
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
	static Board* _board;
	// �Ҹ���
	~ChessPiece() {};

};

class Pawn : public ChessPiece
{
private:
	bool firstMove;
	//bool isMove;
	bool isrightAtk;
	bool isleftAtk;
public:
	Pawn();
	Pawn(Piecetype type, Team team, bool firstMove);
	void firstMoveOff();
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
};

class Rock : public ChessPiece
{
private:
public:
	Rock();
	Rock(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
};

class Bishop : public ChessPiece
{
private:
public:
	Bishop();
	Bishop(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
};

class Knight : public ChessPiece
{
private:
public:
	Knight();
	Knight(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
};

class Queen : public ChessPiece
{
private:
public:
	Queen();
	Queen(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
};

class King : public ChessPiece
{
private:
public:
	King();
	King(Piecetype type, Team team);
	virtual void CheckPossibleMovement(int x, int y);
	virtual void Move(int x, int y);
};
#endif