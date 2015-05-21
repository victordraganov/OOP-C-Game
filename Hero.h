#pragma once

#include"Unit.h"
#include"Item.h"

const int InitialHeroHealth = 100;
const int InitialHeroDamage = 20;
const int InitialHeroArmor = 10;
const int InitialHeroLevel = 1;
const int InitialHeroMovementSpeed = 200;
const int InitialInventoryCapacity = 6;

class Hero : public Unit {
public:
	void PickupItem();
	Hero() : Unit() {};
	Hero(int, int, Body*, int, int, int);
	~Hero() {};
private:
	int experience;
	int level;
	int movementSpeed;
	std::vector<Item> inventory;
};