#include"Draw.h"

void DrawPixel(Pixel pixel, HDC mydc)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			SetPixel(mydc, pixel.x + i, pixel.y + j, pixel.color);

		}
	}
}

void DeletePixel(Pixel pixel, HDC mydc)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			SetPixel(mydc, pixel.x + i, pixel.y + j, RGB(0, 0, 0));

		}
	}
}

void DrawMap(Map map, HDC mydc) {
	Pixel wall;

	for (size_t i = 0; i < 82; i++)
	{
		for (size_t j = 0; j < 122; j++)
		{
			wall.x = j * 5;
			wall.y = i * 5;
			if (map.body[i][j] == '#')
			{
				wall.color = RGB(255, 255, 255);
				DrawPixel(wall, mydc);
			}
			else if (map.body[i][j] == 'V')
			{
				wall.color = RGB(255, 0, 0);
				DrawPixel(wall, mydc);
			}
		}
	}
}
