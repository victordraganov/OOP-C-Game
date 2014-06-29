#include<iostream>
#include<fstream>
#include"Draw.h"
#include"Dynamics.h"

using namespace std;

void clearscreen();

int main()
{
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Hide the vertical scrollbar, because it messes up with the drawing.
	ShowScrollBar(myconsole, SB_VERT, false);
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);
	//Choose any color
	COLORREF ColWhite = RGB(255, 255, 255);
	COLORREF ColRed = RGB(0, 0, 255);
	COLORREF ColBlue = RGB(0, 0, 255);

	Pixel hero1;
	hero1.color = ColWhite;
	hero1.x = 50;
	hero1.y = 50;

	Pixel hero2;
	hero2.color = ColBlue;
	hero2.x = 100;
	hero2.y = 100;
	
	Map map;
	ifstream level;
	level.open("map.txt", ios::in);
	if (level.is_open())
	{
		//cout << "open";
	}
	else
	{
		system("pause");
	}
	
	for (size_t i = 0; i < 82; i++)
	{
		for (size_t j = 0; j < 122; j++)
		{
			char ch = level.get();
			if (ch != '\n')
			{
				map.body[i][j] = ch;
			}
			else
			{
				j--;
			}
		}
	}
	level.close();

	DrawMap(map, mydc);

	while (true)
	{
		clearscreen();
		GetCommand(hero1, hero2);

		DrawPixel(hero1, mydc);
		DrawPixel(hero2, mydc);

		Sleep(20);

		DeletePixel(hero1, mydc);
		DeletePixel(hero2, mydc);
	}

	ReleaseDC(myconsole, mydc);
	cin.ignore();

	return 0;
}

void clearscreen()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD NewSBSize;
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &info);
}
