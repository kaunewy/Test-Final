#pragma once
#include "Map.h"
#include "AStar.h"

class Game
{
#pragma region Functions
public:
	void GameLoop();
	void MoveDwarf(Colony& _colony, const Map& _map);
#pragma endregion
};

