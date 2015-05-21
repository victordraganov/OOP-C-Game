#include"Unit.h"
#include"Map.h"

Unit::Unit() : GameObject(){
	this->health = 100;
	this->damage = 20;
	this->armor = 10;
	this->energy = InitialUnitEnergy;
}

Unit::Unit(int x, int y, Body* body, int health, int damage, int armor)
: GameObject(x, y, body) {
	this->health = health;
	this->damage = damage;
	this->armor = armor;
	this->energy = InitialUnitEnergy;
}

Unit::~Unit() {}

bool Unit::TakeDamage(int damage) {
	int trueDamage = damage - this->armor; // Fix True damage
	this->health -= trueDamage;
	bool stillAlive = true;
	if (this->health < 0)
	{
		stillAlive = false;
	}
	
	return stillAlive;
}

void Unit::Hit() {
	this->energy -= 20;
}

//std::vector<GameObject*> Unit::NearObject(Map& map) {
//	int x = this->GetX();
//	int y = this->GetY();
//	int width = this->GetBody()->Width();
//	int height = this->GetBody()->Height();
//	std::string directions = this->GetDirectionsForObjectSurrounding(map);
//
//
//}
