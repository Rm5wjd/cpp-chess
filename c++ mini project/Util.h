#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__

#include <Windows.h>
#include <stdio.h>

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray
};


#endif


void SetColor(int textColor, int bgColor);
void gotoxy(int x, int y);
COORD getxy();
void SwitchingConsoleCursor(bool flag, int size);
void setBgColor(int bgcolor);