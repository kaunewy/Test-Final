#include "Dwarf.h"

Dwarf::Dwarf(const Job& _job, const u_int& _satiaty, const Position& _current)
{
	job = _job;
	satiaty = _satiaty;
	posDwarf = _current;
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

void Dwarf::FindPath(const Position& _goal, const vector<vector<pair<TileType, ObjectType>>>& _map)
{
	if(movement.empty())
	{
		AStar<TileType, ObjectType> _aStar(_map, posDwarf, _goal);
		movement = _aStar.AStarFunction();
	}
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

void Dwarf::ChangeJob()
{
	Menu _changeJob;
	for (u_int _i = 0; _i < J_COUNT; _i++)
	{
		_changeJob.AddOption(GetJobName(static_cast<Job>(_i)), [this, _index = _i]{SetDwarfJob(static_cast<Job>(_index));});
	}
	_changeJob.Choice();
	movement.clear();
}

string Dwarf::GetJobName(Job _job)
{
	switch (_job)
	{
	case J_LUMBERJACK:
		return "Bucheron";
		break;
	case J_BLACK_SMITH:
		return "Forgeron";
		break;
	case J_VILLAGER:
		return "Villageois";
		break;
	case J_HUNTER:
		return "Chasseur";
		break;
	case J_KNIGHT:
		return "Chevalier";
		break;
	default:
		return "Nothing";
		break;
	}
}



