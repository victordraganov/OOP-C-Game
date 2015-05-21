#pragma once

#include<vector>
//#include<fstream> //TO DO LoadingFrom
#include"ColorBlock.h" //Fix body and working with body .. Is it nessesary to build body or just vector<ColorBlock>

class Body {
public:
	Body(std::vector<ColorBlock>, int, int);
	Body(const Body&);
	~Body();

	void AddBlock(ColorBlock);
	std::vector<ColorBlock> Blocks() const { return blocks; };
	int Width() const;
	int Height() const;
private:
	std::vector<ColorBlock> blocks;
	int width;
	int height;
};