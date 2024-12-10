#include "Dwarf.h"

Dwarf::Dwarf(Job _job, u_int _satiaty)
{
	job = _job;
	satiaty = _satiaty;
}

bool Dwarf::Task(const TileType& _tile)
{
	bool _goodTool = false;
	for (Tool _tool : tools)
	{
		switch (_tool.GetCategory())
		{
		case CT_AXE:
			_goodTool = _tile == WOOD;
			break;
		case CT_SWORD:
			_goodTool = _tile == FOOD;
			break;
		case CT_PICKAXE:
			_goodTool = _tile == STONE;
			break;
		case CT_BUCKET:
			_goodTool = _tile == WATER;
			break;
		default:
			break;
		}
	}
	return _tile == job && _goodTool;
}

void Dwarf::Move()
{
	if (!movement.empty())
	{
		posDwarf = movement[movement.size() - 1];
		movement.pop_back();
	}
}

void Dwarf::FindPath(const Position& _goal, const vector<vector<TileType>>& _map)
{
	AStar<TileType> _aStar(_map, posDwarf, _goal);
	movement = _aStar.AStarFunction();
}

void Dwarf::Feed(const u_int& _quantityFood)
{
	satiaty += _quantityFood;
	if (satiaty > 100) satiaty = 100;
}

void Dwarf::AddTool(Tool _tool)
{
	tools.push_back(_tool);
}



