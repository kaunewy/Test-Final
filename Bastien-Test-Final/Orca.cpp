#include "Orca.h"

Orca::Orca(cu_int& _life, cu_int& _damage, const Position& _pos, const string& _name) 
	: Enemy(_life, _damage, _pos, _name)
{
}

bool Orca::DestroyBuilding()
{
	//TODO
	return true;
}
