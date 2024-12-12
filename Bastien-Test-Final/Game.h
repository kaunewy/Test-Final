#pragma once
#include "Map.h"
#include "AStar.h"
#include <chrono>
#include <thread>

class Game
{
#pragma region Functions
public:
	void GameLoop();
	void MoveDwarf(Colony& _colony, const Map& _map);
#pragma endregion
};

