#pragma once
#include "Enemy.h"
class Orca : public Enemy
{

#pragma region Constructor
public:
	Orca(cu_int& _life, cu_int& _damage, const Position& _pos, const string& _name);
#pragma endregion

#pragma region Functions
public:
	virtual bool DestroyBuilding() override;
#pragma endregion 
};

