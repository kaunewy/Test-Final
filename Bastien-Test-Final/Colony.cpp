#include "Colony.h"

void Colony::AddToResource(const TileType& _tile)
{
	for (auto _dwarf : dwarfs)
	{
		if (_dwarf.second.Task(_tile))
		{
			switch (_dwarf.second.GetDwarfJob())
			{
			case J_HUNTER:
				for (auto _resource : resources)
				{
					if (_resource.first == R_FOOD)
					{
						_resource.second += 10;
						break;
					}
				};
				resources.push_back(make_pair(R_FOOD, 10));
				break;
			case J_KNIGHT:
					//TODO
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
}

void Colony::CreateBuilding()
{
	
}

void Colony::CreateTool(Dwarf _dwarf, const string& _nameTool, const u_int& _damage, const CategoriesTools& _category)
{
	_dwarf.AddTool(Tool(_nameTool, _damage, _category));
}
