#pragma once
#include "Macro.h"
#include <vector>
#include "Dwarf.h"

enum Resources
{
	R_WOOD,
	R_STONE,
	R_WATER,
	R_FOOD,

	R_COUNT
};

class Colony
{
	vector<pair<Resources, u_int>> resources;
	vector<pair<string, Dwarf>> dwarfs;

#pragma region Functions
public:
	void AddToResource(const TileType& _tile);
	void CreateBuilding();
	void CreateTool(Dwarf _dwarf, const string& _nameTool, const u_int& _damage, const CategoriesTools& _category);
#pragma endregion
};

