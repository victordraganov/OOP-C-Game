#include"Renderer.h"

Renderer::Renderer() {
	HWND myconsole = GetConsoleWindow();
	HDC myDC = GetDC(myconsole);
	this->myDC = myDC;
}

void Renderer::DrawObject(const GameObject* object) {
	int nextBlock = 0;
	for (int i = 0; i < object->GetBody()->Height(); i++)
	{
		for (int j = 0; j < object->GetBody()->Width(); j++)
		{
			DrawBlock((object->GetX() + j) * 6, (object->GetY() + i) * 6, object->GetBody()->Blocks()[nextBlock]);
			++nextBlock;
		}
	}
}

void Renderer::DrawAll(const std::vector<GameObject>& objects) {
	for (int i = 0; i < objects.size(); i++)
	{
		DrawObject(&objects[i]);
	}
}

void Renderer::DeleteObject(const GameObject* object) {
	DeleteRectangle(object->GetX(), object->GetY(), object->GetBody()->Width(), object->GetBody()->Height());
}

void Renderer::DeleteRectangle(int x, int y, int width, int height) {
	x = x * 6;
	y = y * 6; // One field on the map is a square with side 6 real pixels on the monitor;
	for (int i = 0; i < height * 2; i++)
	{
		for (int j = 0; j < width * 2; j++)
		{
			DeletePixel(x + j * 3, y + i * 3);
		}
	}
}

void Renderer::DrawBlock(int x, int y, ColorBlock& block) {
	for (size_t i = 0; i < 4; i++)
	{
		if (block.pixels[i] != NULL)
		{
			DrawPixel(x + (i % 2) * 3, y + (i / 2) * 3, block.pixels[i]);
		}
	}
}

void Renderer::DrawPixel(int x, int y, COLORREF color)
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			SetPixel(myDC, x + i, y + j, color);
		}
	}
}

void Renderer::DeletePixel(int x, int y)
{
	DrawPixel(x, y, BLACK);
}

void Renderer::SetCursor(const int x, const int y) {
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Renderer::DrawMapObjects(Map& map) {
	DrawAll(map.allObjects);
}