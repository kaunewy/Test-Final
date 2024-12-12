#pragma once
#include "Map.h"
#include "AStar.h"
#include <chrono>
#include <thread>
#include "Orca.h"
#include "Giant.h"

class Game
{
#pragma region Functions
public:
	void GameLoop();
	void MoveDwarfs(Colony& _colony, const Map& _map);
	void MoveEnemies(Map& _map);
#pragma endregion
};

