#include"Map.h"

std::string Map::GetDirectionsForObjectSurrounding(GameObject* object) {
	std::string directionsForObjectSurrounding = "    "; // string with information for neighbouring mapField
	int x = object->GetX();
	int y = object->GetY();
	int width = object->GetBody()->Width();
	int height = object->GetBody()->Height();

	for (int i = 0; i < height; i++)
	{
		if (this->fields[y + i][x - 1] != NULL ||
			this->fields[y + i][x - 2] != NULL)
		{
			directionsForObjectSurrounding[0]= 'L'; // L for left direction
		}

		if (this->fields[y + i][x + width] != NULL ||
			this->fields[y + i][x + width + 1] != NULL)
		{
			directionsForObjectSurrounding[1] = 'R'; // R for right direction
		}
	}

	for (int i = 0; i < width; i++)
	{
		if (this->fields[y - 1][x + i] != NULL ||
			this->fields[y - 2][x + i] != NULL)
		{
			directionsForObjectSurrounding[2] = 'U'; // U for up direction
		}

		if (this->fields[y + height][x + i] != NULL ||
			this->fields[y + height + 1][x + i] != NULL)
		{
			directionsForObjectSurrounding[3] = 'D'; // D for down direction
		}
	}

	return directionsForObjectSurrounding;
}

void Map::Move(GameObject* object, char direction, int amplitude) {
	
	InitiallizeFields(object->GetX(), object->GetY(), object->GetBody()->Width(), object->GetBody()->Height(), NULL);
	if (direction == 'R')
	{
		object->SetX(object->GetX() + amplitude) ;
	}
	else if (direction == 'L')
	{
		object->SetX(object->GetX() - amplitude);
	}
	else if (direction == 'D')
	{
		object->SetY(object->GetY() + amplitude);
	}
	else if (direction == 'U')
	{
		object->SetY(object->GetY() - amplitude);
	}
	InitiallizeObjectFields(object);
	//InitiallizeFields(object->GetX(), object->GetY(), object->GetBody()->Width(), object->GetBody()->Height(), object);
}

void Map::InitiallizeObjectFields(GameObject* object) {
	int objectWidth = object->GetBody()->Width();
	int objectHeight = object->GetBody()->Height();
	int objectX = object->GetX();
	int objectY = object->GetY();
	
	for (size_t i = objectX; i < objectX + objectWidth; i++)
	{
		for (size_t j = objectY; j < objectY + objectHeight; j++) // REIMPLEMENT maby
		{
			this->fields[j][i] = object;
		}
	}
}

void Map::InitiallizeFields(int x, int y, int width, int height, GameObject* object) {
	// width and height represent the measures of a rectangle of the map, which will be initiallized
	// x and y are the coordinates of the top left field of the rectangle
	for (size_t i = x; i < x + width; i++)
	{
		for (size_t j = y; j < y + height; j++) // REIMPLEMENT maby
		{
			this->fields[j][i] = object;
		}
	}
}