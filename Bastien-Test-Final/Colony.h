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
	vector<pair<string, Dwarf*>> dwarfs;

#pragma region Getters
public:
	inline vector<pair<string, Dwarf*>> GetDwarfs() const
	{
		return dwarfs;
	}
	inline vector<pair<Resources, u_int>> GetResources() const
	{
		return resources;
	}
#pragma endregion

#pragma region Functions
public:
	void AddDwarf(const string& _name, const Dwarf& _dwarf);
	void AddToResource(Dwarf _dwarf, const TileType& _tile);
	void CreateBuilding();
	void CreateTool(Dwarf _dwarf, const string& _nameTool, const u_int& _damage, const CategoriesTools& _category);
	string GetNameByResource(const Resources& _resource) const;
#pragma endregion
};

