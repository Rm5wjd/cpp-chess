#include "Util.h"

void SetColor(int textColor, int bgColor)
{
	int color = textColor + bgColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD getxy()
{
	CONSOLE_SCREEN_BUFFER_INFO cs;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cs);
	return cs.dwCursorPosition;
}

void SwitchingConsoleCursor(bool flag, int size)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = size;
	cursorInfo.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void setBgColor(int bgcolor) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor & 0xf) << 4) | (info.wAttributes & 0xf));
}

