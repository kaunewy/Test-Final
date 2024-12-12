#pragma once
#include "Macro.h"
#include "Position.h"
#include <vector>
#include "TileType.h"
#include "AStar.h"
#include "ObjectType.h"

class Enemy
{
	u_int life;
	u_int damage;
	Position pos;
	string name;
	vector<Position> movement;

#pragma region Getters
public:
	inline u_int Getlife() const
	{
		return life;
	}
	inline u_int GetDamage() const
	{
		return damage;
	}
	inline Position GetPos() const
	{
		return pos;
	}
#pragma endregion

#pragma region Constructor
public:
	Enemy() = default;
	Enemy(cu_int& _life, cu_int& _damage, const Position& _pos, const string& _name)
	{
		life = _life;
		damage = _damage;
		pos = _pos;
		name = _name;
	}
#pragma endregion

#pragma region Functions
public:
	virtual bool DestroyBuilding() = 0;
	void Move();
	void FindPath(const Position& _goal, const vector<vector<pair<TileType, ObjectType>>>& _map);
#pragma endregion
};

