#pragma once
#include "Macro.h"
#include "Tool.h"
#include <vector>
#include "AStar.h"
#include "TileType.h"


enum Job
{
	J_LUMBERJACK,
	J_BLACK_SMITH,
	J_VILLAGER,
	J_HUNTER,
	J_KNIGHT,


	J_COUNT
};

class Dwarf
{
	Job job;
	u_int satiaty;
	vector<Tool> tools;
	Position posDwarf;
	vector<Position> movement;
#pragma region Getters
public:
	inline Job GetDwarfJob() const
	{
		return job;
	}

	inline u_int GetSatiaty() const
	{
		return satiaty;
	}
	inline Position GetPos() const
	{
		return posDwarf;
	}
	void SetDwarfJob(const Job& _job)
	{
		job = _job;
	}
	void SetSatiaty(u_int _satiaty)
	{
		satiaty = _satiaty;
	}
#pragma endregion

#pragma region Construtor
public:
	Dwarf(Job _job = J_VILLAGER, u_int _satiaty = 100);
#pragma endregion

#pragma region Functions
	bool Task(const TileType& _tile);
	void Move();
	void FindPath(const Position& _goal, const vector<vector<TileType>>& _map);
	void Feed(const u_int& _quantityFood);
	void AddTool(Tool _tool);
#pragma endregion

};

