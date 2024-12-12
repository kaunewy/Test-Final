#pragma once
#include "Dwarf.h"

enum TypeHouse
{
	TH_SMALL,
	TH_BIG,

	TH_COUNT
};

class House
{
	vector<Dwarf*> dwarfs;
	TypeHouse typeHouse;
	Position pos;

#pragma region Getters
public:
	inline TypeHouse GetTypeHouse() const
	{
		return typeHouse;
	}
	inline vector<Dwarf*> GetDwarfsInHouse() const
	{
		return dwarfs;
	}
	inline Position GetPos() const
	{
		return pos;
	}
#pragma endregion

#pragma region Constructor
public:
	House(const TypeHouse& _typeHouse = TH_SMALL, const Position& _pos = Position(0,0));
#pragma endregion

#pragma region Functions
public:
	void AddDwarfToHouse(Dwarf& _dwarf);
#pragma endregion
};

