#include"Body.h"

Body::Body(std::vector<ColorBlock> blocks, int width, int height) {
	for (int i = 0; i < blocks.size(); i++)
	{
		AddBlock(blocks[i]);
	}

	this->width = width;
	this->height = height;
}

Body::Body(const Body& other) {
	this->width = other.Width();
	this->height = other.Height();
	this->blocks = other.blocks;
}

Body::~Body() {}

void Body::AddBlock(ColorBlock block) {
	this->blocks.push_back(block);
}

int Body::Width() const{
	return this->width;
}

int  Body::Height() const{
	return this->height;
}