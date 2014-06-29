#include"Dynamics.h"

void GetCommand(Pixel & pl1, Pixel & pl2) {
	HandlePlayerOne(pl1);
	HandlePlayerTwo(pl2);
}

void GetCommand(Pixel & pl1)
{
	HandlePlayerOne(pl1);
}

void HandlePlayerOne(Pixel & pl1)
{
	if (GetAsyncKeyState(VK_LEFT) && pl1.x > 5)
	{
		pl1.x--;
	}if (GetAsyncKeyState(VK_RIGHT))
	{
		pl1.x++;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		pl1.y--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		pl1.y++;
	}
}

void HandlePlayerTwo(Pixel & pl2)
{
	if (GetAsyncKeyState(0x41))
	{
		pl2.x--;
	}
	if (GetAsyncKeyState(0x44))
	{
		pl2.x++;
	}
	if (GetAsyncKeyState(0x57))
	{
		pl2.y--;
	}
	if (GetAsyncKeyState(0x53))
	{
		pl2.y++;
	}
}
