#pragma once

#include"GameObject.h"
#include"Map.h"

class Renderer{
public:
	Renderer();
	~Renderer() {};
	void DrawObject(const GameObject*);
	void DeleteObject(const GameObject*);
	void DeleteRectangle(int, int, int, int);
	void DrawAll(const std::vector<GameObject>&);
	void DrawMapObjects(Map&);
	void SetCursor(const int, const int);
private:
	HDC myDC;
	void DrawBlock(int, int, ColorBlock&);
	void DrawPixel(int, int, COLORREF);
	void DeletePixel(int, int);
	
};
