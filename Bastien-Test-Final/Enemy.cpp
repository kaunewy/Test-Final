#include "Enemy.h"

void Enemy::Move()
{
	if (!movement.empty())
	{
		pos = movement[movement.size() - 1];
		movement.pop_back();
	}
}

void Enemy::FindPath(const Position& _goal, const vector<vector<TileType>>& _map)
{
	if (movement.empty())
	{
		AStar<TileType> _aStar(_map, pos, _goal);
		movement = _aStar.AStarFunction();
	}
}
