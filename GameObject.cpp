#include"GameObject.h"

GameObject::GameObject() {
	SetX(0);
	SetY(0);
	this->exist = true;
}

GameObject::GameObject(int x, int y, Body* body) {
	SetX(x);
	SetY(y);
	this->exist = true;
	this->body = body;
}

GameObject::GameObject(const GameObject& other) {
	SetX(other.GetX());
	SetY(other.GetY());
	this->body = other.body;
}

GameObject::GameObject(std::istream& file) {
	
}

GameObject::~GameObject() {
	//TO DO
}

void GameObject::SetX(int x) {
	if (x < 0)
	{
		return; //Exeption
	}
	this->x = x;
}

void GameObject::SetY(int y) {
	if (y < 0)
	{
		return; //Exeption
	}
	this->y = y;
}