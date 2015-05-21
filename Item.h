#pragma once

#include"GameObject.h"
#include"ItemTypes.h"

class Item : public GameObject{
private:
	ItemType type;
	bool pickedUp;
	int boost;
public:
	Item(int, int, Body*, int, ItemType);
	~Item(){};
	ItemType GetType() const;
};