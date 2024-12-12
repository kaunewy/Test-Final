#include "House.h"

House::House(const TypeHouse& _typeHouse, const Position& _pos)
{
	typeHouse = _typeHouse;
	pos = _pos;
}

void House::AddDwarfToHouse(Dwarf& _dwarf)
{
	dwarfs.push_back(&_dwarf);
}
