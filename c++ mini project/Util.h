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