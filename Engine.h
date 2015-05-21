#pragma once

#include"GameObject.h"
#include"Renderer.h"
#include"ObjectBuilder.h"
#include"CommandHandler.h"

class Engine { // Using the singleton design pattern, in order to make sure only one Engine instance is created.
public:
	void Run(); // Runs the game.
	static Engine& Instantiate(); 
private:
	Engine();
	~Engine();
	Engine(const Engine&); //Making sure no one calls copy constructor or operator '='
	void operator =(const Engine&);

	void MoveObject(GameObject&, Map&, char);
	void PauseGame();
	//void LoadMap();
	void ReleaseMapMemory();

	Hero pl1;
	Hero pl2;
	ObjectBuilder builder;
	Renderer renderer;
	CommandHandler commandHandler;
	Map map;
};