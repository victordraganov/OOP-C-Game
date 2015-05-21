#include"ObjectBuilder.h"

ObjectBuilder::ObjectBuilder() {

}

ObjectBuilder::~ObjectBuilder() {

}

GameObject ObjectBuilder::CreateObject(int x, int y, char ch) {
	for (size_t i = 0; i < bodiesCount; i++)
	{
		if (names[i][0] == ch)
		{
			GameObject object(x, y, &bodies[i]);
			return object;
		}
	}
	
	return CreateObject(x, y, 'W');
}

Hero ObjectBuilder::BuildHero(int x, int y, char ch) {
	Body* body = NULL;
	for (size_t i = 0; i < bodiesCount; i++)
	{
		if (this->names[i][0] == ch)
		{
			body = &this->bodies[i];
		}
	}
	Hero pl(x, y, body, 100, 20, 20); //It's default for now
	return pl;
}

void ObjectBuilder::LoadBodies() {
	std::ifstream objects;
	objects.open("../Resourses/ObjectBodies/objects.txt", std::ios::in);
	if (!objects.good())
	{
		//Exeption!
	}

	char* str = new char[30]; //Make constant
	objects.getline(str, 30);
	this->bodiesCount = ConvertToNumber(str);

	for (size_t i = 0; i < bodiesCount; i++)
	{
		std::string line;
		objects.getline(str, 30);
		line = str;
		names.push_back(line);
	}

	objects.close();
	delete[] str;
	for (size_t i = 0; i < bodiesCount; i++)
	{
		Body body = ExtractBodyFromFile(ExtractName(this->names[i]));
		this->bodies.push_back(body);
	}
}

Map ObjectBuilder::BuildMapFromFile(int mapNumber) {
	Map loadedMap; // Will be returned after initialized
	std::ifstream mapFile;
	std::string path = "../Resourses/Maps/map" + std::to_string(mapNumber) + ".txt"; //Make constant!
	mapFile.open(path, std::ios::in);
	if (!mapFile.good())
	{
		// throw Exeption
	}
	char* str = new char[3]; // Make constant! 

	mapFile.getline(str, 3);
	int width = ConvertToNumber(str);
	loadedMap.width = width;

	mapFile.getline(str, 3);
	int height = ConvertToNumber(str);
	loadedMap.height = height;

	delete[] str;

	for (size_t i = 0; i < height; i++)
	{
		GameObject** fieldLine = new GameObject*[width];
		loadedMap.fields.push_back(fieldLine);
		for (size_t j = 0; j < width; j++)
		{
			loadedMap.fields[i][j] = NULL; // There isn't any GameObjects on the map yet
		}
	}

	char** charMatrix;
	charMatrix = BuildCharMatrix(mapFile, width, height); // Using resourse file to obrain the map frame
	mapFile.close(); // closing the resourse file

	for (size_t i = 0; i < width; i++) // width -> moving on the X-axis
	{
		for (size_t j = 0; j < height; j++) // height -> moving on the Y-axis
		{
			if (charMatrix[j][i] != ' ' && charMatrix[j][i] != 'H' && charMatrix[j][i] != 'h')
			{
				GameObject object = CreateObject(i, j, charMatrix[j][i]);
				loadedMap.allObjects.push_back(object);
				loadedMap.InitiallizeObjectFields(&object);
			}
			else if (charMatrix[j][i] == 'H')
			{
				loadedMap.heroOneX = i;
				loadedMap.heroOneY = j;
			}
			else if (charMatrix[j][i] == 'h') {
				loadedMap.heroTwoX = i;
				loadedMap.heroTwoY = j;
			}
		}
	}

	for (size_t i = 0; i < height; i++)
	{
		delete[] charMatrix[i];
	}

	delete[] charMatrix;
	//TO DO : ValidateHeroCoords(); ValidateObjectFromCharMatrix
	
	return loadedMap;
}

Body ObjectBuilder::ExtractBodyFromFile(std::string name) {
	std::ifstream file;
	std::string path = "../Resourses/ObjectBodies/" + name + ".txt";
	file.open(path);
	char* str = new char[30]; // Take a look here -> reimplement !
	file.getline(str, 30);
	size_t width = ConvertToNumber(str); //Extracting width from file
	file.getline(str, 30);
	size_t height = ConvertToNumber(str); //Extracting height from file
	delete str;

	char** charMatrix;
	charMatrix = BuildCharMatrix(file, width*2, height*2); // * 2 Explain

	return BuildBody(charMatrix, width, height);
	for (size_t i = 0; i < height * 2; i++)
	{
		delete[] charMatrix[i];
	}

	delete charMatrix;

}

Body ObjectBuilder::BuildBody(char** characters, size_t width, size_t height) { // width and height for the body, NOT the array!
	std::vector<ColorBlock> blocks;
	std::string blockStr = "";
	for (size_t i = 0; i < height * 2; i += 2)
	{
		for (size_t j = 0; j < width * 2; j += 2)
		{
			blockStr += characters[i][j];
			blockStr += characters[i][j + 1];
			blockStr += characters[i + 1][j];
			blockStr += characters[i + 1][j + 1];
			ColorBlock block = BuildBlock(blockStr);
			blocks.push_back(block);
			blockStr = "";
		}
	}

	Body body(blocks, width, height);
	return body;
}

ColorBlock ObjectBuilder::BuildBlock(std::string blockStr) {
	ColorBlock block;
	block.pixels = new COLORREF[4];
	for (size_t i = 0; i < 4; i++)
	{
		block.pixels[i] = GetColor(blockStr[i]);
	}

	return block;
}

char** ObjectBuilder::BuildCharMatrix(std::istream& file, size_t width, size_t height) {
	char** frame = new char*[height];
	for (size_t i = 0; i < height; i++)
	{
		frame[i] = new char[width + 1]; // width + 1 because of the terminating zero getLine puts
	}

	for (size_t i = 0; i < height; i++)
	{
		file.getline(frame[i], width + 1);
	}

	return frame;
}

COLORREF ObjectBuilder::GetColor(char ch) {
	if (ch == 'R')
	{
		return RED;
	}
	if (ch == 'G')
	{
		return GREEN;
	}
	if (ch == 'B')
	{
		return BLUE;
	}
	if (ch == 'Y')
	{
		return YELLOW;
	}
	if (ch == 'N')
	{
		return BROWN;
	}
	if (ch == 'W')
	{
		return WHITE;
	}
	if (ch == 'A')
	{
		return GRAY;
	}
	if (ch == ' ')
	{
		return BLACK;
	}
	return NULL;
}

size_t ObjectBuilder::ConvertToNumber(char* str) {
	size_t len = std::strlen(str);
	size_t number = 0;
	for (size_t i = 0; i < len; i++)
	{
		number += ((int)str[i]- 48) * pow(10, len - i -1);
	}
	
	return number;
}

std::string ObjectBuilder::ExtractName(std::string def) {
	return def.substr(2, def.size());
}