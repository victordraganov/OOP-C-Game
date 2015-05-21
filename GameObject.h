#pragma once

#include"Body.h"
//#include"Map.h"

class GameObject{
public:
	GameObject();
	GameObject(int,int, Body*);
	GameObject(const GameObject&);
	GameObject(std::istream&);
	~GameObject();
	
	Body* GetBody() const { return body; };
	int GetX() const { return x; };
	int GetY() const { return y; };
	
	void SetX(int);
	void SetY(int);
private:
	int x;
	int y;
	bool exist;
	Body* body;
};