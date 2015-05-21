#include"Hero.h"

Hero::Hero(int x, int y, Body* body, int health, int damage, int armor)
: Unit(x, y, body, health, damage, armor) {
	this->experience = 0;
	this->level = InitialHeroLevel;
	this->movementSpeed = InitialHeroMovementSpeed;
}