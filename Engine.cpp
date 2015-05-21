#include"Engine.h"
//#include"Player.h"

Engine::Engine() {
	Renderer ren;
	this->renderer = ren;
	CommandHandler handler;
	this->commandHandler = handler;
	ObjectBuilder b;
	this->builder = b;

	builder.LoadBodies();
	Map m = builder.BuildMapFromFile(1);
	this->map = m;
	Hero hero1 = builder.BuildHero(map.heroOneX, map.heroOneY, '1');
	this->pl1 = hero1;
	Hero hero2 = builder.BuildHero(map.heroTwoX, map.heroTwoY, '2');
	this->pl2 = hero2;

	map.InitiallizeObjectFields(&pl1);
	map.InitiallizeObjectFields(&pl2);

	//for (size_t i = 0; i < map.height; i++) // This is a check if the fields are initiallized
	//{
	//	for (size_t j = 0; j < map.width; j++)
	//	{
	//		if (map.fields[i][j] == NULL)
	//		{
	//			std::cout << 'N';
	//		}
	//		else
	//		{
	//			std::cout << 'O';
	//		}
	//	}
	//	std::cout << std::endl;
	//}

}

Engine& Engine::Instantiate() {
	static Engine engine;
	return engine;
}

Engine::~Engine() {
	for (size_t i = 0; i < map.height; i++)
	{
		delete[] map.fields[i];
	}
}

void Engine::Run() {
	renderer.SetCursor(30, 0);
	renderer.DrawMapObjects(map);
	renderer.DrawObject(&pl1);
	//Play("../Resourses/AIAI.wav");
	renderer.DrawObject(&pl2);
	//Play("..resourses/orders.wav");

	while (true)
	{
		char primaryCommand = commandHandler.GetPrimaryCommand();
		char player2Command = commandHandler.GetPlayer2Command();
		std::string pl1Surrounding = map.GetDirectionsForObjectSurrounding(&pl1);
		std::string pl2Surrounding = map.GetDirectionsForObjectSurrounding(&pl2);
		if (primaryCommand != '\0' && pl1Surrounding.find(primaryCommand))
		{
			MoveObject(pl1, map, primaryCommand);
		}

		if (player2Command != '\0' && pl2Surrounding.find(player2Command))
		{
			MoveObject(pl2, map, player2Command);
		}

		if (primaryCommand == 'P')
		{
			PauseGame();
		}

		Sleep(300);
	}
}

void Engine::MoveObject(GameObject& object, Map& map, char direction) {
		renderer.DeleteObject(&object);
		map.Move(&object, direction, 1);
		renderer.DrawObject(&object);
		return;
}

void Engine::PauseGame() {
	while (true)
	{
		Sleep(500);
		if (GetAsyncKeyState(0x50))
		{
			break;
		}
	}
}