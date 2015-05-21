#pragma once

#include<fstream>
#include<iostream>
#include<math.h>
#include<string>
#include"GameObject.h"
#include"Hero.h"
#include"Map.h"

class ObjectBuilder {
public:
	Map BuildMapFromFile(int);
	GameObject CreateObject(int, int, char);
	Hero BuildHero(int, int, char);
	void LoadBodies();
	//void InitiallizeObjectFields(GameObject*, Map&);
	ObjectBuilder();
	~ObjectBuilder();
private:
	ObjectBuilder(const ObjectBuilder&);
	std::string ExtractName(std::string);
	Body ExtractBodyFromFile(std::string);
	Body BuildBody(char**, size_t, size_t);
	ColorBlock BuildBlock(std::string);
	char** BuildCharMatrix(std::istream&, size_t, size_t);
	COLORREF GetColor(char);
	//TO DO : ValidateHeroCoords();
	size_t ConvertToNumber(char*);
	size_t bodiesCount;
	std::vector<std::string> names;
	std::vector<Body> bodies;
};