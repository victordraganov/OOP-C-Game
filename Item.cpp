#include"Item.h"

Item::Item(int x, int y, Body* body, int boost, ItemType type) : GameObject(x, y, body) {
	pickedUp = false;
	boost = boost;
}

ItemType Item::GetType() const {
	return type;
}