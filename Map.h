#pragma once

#include"GameObject.h"

struct Map{
	std::string GetDirectionsForObjectSurrounding(GameObject*);
	void InitiallizeFields(int, int, int, int, GameObject*); // make private
	void Move(GameObject*, char, int);
	void InitiallizeObjectFields(GameObject* object);

	std::vector<GameObject> allObjects;
	std::vector<GameObject**> fields;
	int width;
	int height;
	int heroOneX;
	int heroOneY;
	int heroTwoX;
	int heroTwoY;
};

//const size_t MaxPlayingField width
//const size_t MaxPlayingField height