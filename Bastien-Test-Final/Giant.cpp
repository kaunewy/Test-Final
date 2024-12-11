#include "Giant.h"

Giant::Giant(const TileType& _spawn, cu_int& _life, cu_int& _damage, const Position& _pos, const string& _name)
	: Enemy(_life, _damage, _pos, _name)
{
	spawn = _spawn;
}

bool Giant::DestroyBuilding()
{
	return false;
}
