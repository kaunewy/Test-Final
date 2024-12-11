#include "Colony.h"

void Colony::AddDwarf(const string& _name, const Dwarf& _dwarf)
{
	dwarfs.push_back(make_pair(_name, new Dwarf(_dwarf)));
}

void Colony::AddToResource(Dwarf _dwarf, const TileType& _tile)
{
	if (_dwarf.Task(_tile))
	{
		bool _isFound = false;
		switch (_dwarf.GetDwarfJob())
		{
		case J_HUNTER:
			for (auto _resource : resources)
			{
				if (_resource.first == R_FOOD)
				{
					_resource.second = _resource.second + 10;
					break;
				}
			};
			resources.push_back(make_pair(R_FOOD, 10));
			break;
		case J_VILLAGER:
			for (auto& _resource : resources)
			{
 				if (_resource.first == R_WATER)
				{
					_resource.second = _resource.second + 10;
					_isFound = true;
					break;
				}
			};
			if(!_isFound)
			{
				resources.push_back(make_pair(R_WATER, 10));
			}
			break;
		case J_LUMBERJACK:
			for (auto _resource : resources)
			{
				if (_resource.first == R_WOOD)
				{
					_resource.second += 10;
					break;
				}
			};
			resources.push_back(make_pair(R_WOOD, 10));
			break;
		case J_BLACK_SMITH:
			for (auto _resource : resources)
			{
				if (_resource.first == R_STONE)
				{
					_resource.second += 10;
					break;
				}
			};
			resources.push_back(make_pair(R_STONE, 10));
			break;
		default:
			break;
		}
	}
}

void Colony::CreateBuilding()
{
	//TODO
}

void Colony::CreateTool(Dwarf _dwarf, const string& _nameTool, const u_int& _damage, const CategoriesTools& _category)
{
	_dwarf.AddTool(Tool(_nameTool, _damage, _category));
}

string Colony::GetNameByResource(const Resources& _resource) const
{
	switch (_resource)
	{
	case R_WOOD:
		return "Bois";
		break;
	case R_WATER:
		return "Eau";
		break;
	case R_STONE:
		return "Pierre";
		break;
	case R_FOOD:
		return "Nourriture";
		break;
	default:
		break;
	}
}
