#include<iostream>
//#include<fstream>
//#include"Renderer.h"
#include"Engine.h"

void clearscreen();

int main()
{
	Engine& engine = (Engine::Instantiate());
	engine.Run();

	//cin.ignore();
	system("pause");
	return 0;
}

//void clearscreen()
//{
//	HANDLE hOut;
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	//COORD NewSBSize;
//	CONSOLE_CURSOR_INFO info;
//	info.dwSize = 100;
//	info.bVisible = TRUE;
//	SetConsoleCursorInfo(hOut, &info);
//}

//void removeScroll() {
//	HANDLE hOut;
//	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
//	COORD NewSBSize;
//	int Status;
//	
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	
//	GetConsoleScreenBufferInfo(hOut, &SBInfo);
//	NewSBSize.X = SBInfo.dwSize.X - 2;
//	NewSBSize.Y = SBInfo.dwSize.Y;
//	
//	Status = SetConsoleScreenBufferSize(hOut, NewSBSize);
//	if (Status == 0)
//	{
//		Status = GetLastError();
//		cout << "SetConsoleScreenBufferSize() failed! Reason : " << Status << endl;
//		exit(Status);
//	}
//	
//	GetConsoleScreenBufferInfo(hOut, &SBInfo);
//}