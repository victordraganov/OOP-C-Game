#pragma once

#include<windows.h>

struct ColorBlock {
	COLORREF* pixels;
};

const COLORREF RED = RGB(255, 0, 0);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF BLUE = RGB(0, 0, 255);
const COLORREF YELLOW = RGB(255, 255, 0);
const COLORREF BROWN = RGB(218, 165, 32);
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF GRAY = RGB(192, 192, 192);
const COLORREF BLACK = RGB(0, 0, 0);
