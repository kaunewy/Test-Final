#pragma once
#include "Enemy.h"
class Giant : public Enemy
{
	TileType spawn;

#pragma region Constructor
	Giant(const TileType& _spawn, cu_int& _life, cu_int& _damage, const Position& _pos, const string& _name);
#pragma endregion

#pragma region Functions
public:
	virtual bool DestroyBuilding() override;
#pragma endregion 
};

