#include"CommandHandler.h"
#include<Windows.h>

char CommandHandler::GetPrimaryCommand()
{
	if (GetAsyncKeyState(VK_LEFT)) //&& pl1.x > 3)
	{
		return 'L';
	}
	if (GetAsyncKeyState(VK_RIGHT)) //&& pl1.x < 80)
	{
		return 'R';
	}
	if (GetAsyncKeyState(VK_UP)) //&& pl1.y > 3)
	{
		return 'U';
	}
	if (GetAsyncKeyState(VK_DOWN)) //&& pl1.y < 70)
	{
		return 'D';
	}
	if (GetAsyncKeyState(0x50))
	{
		return 'P';
	}
}

char CommandHandler::GetPlayer2Command()
{
	if (GetAsyncKeyState(0x41))
	{
		return 'L';
	}
	if (GetAsyncKeyState(0x44))
	{
		return 'R';
	}
	if (GetAsyncKeyState(0x57))
	{
		return 'U';
	}
	if (GetAsyncKeyState(0x53))
	{
		return 'D';
	}
}
