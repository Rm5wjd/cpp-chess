#include "Util.h"

void SetColor(int textColor, int bgColor)
{
	int color = textColor + bgColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}