#pragma once
#include "Macro.h"

enum CategoriesTools
{
	CT_SWORD,
	CT_PICKAXE,
	CT_AXE,
	CT_BUCKET,

	CT_COUNT
};

class Tool
{
	string name;
	u_int damage;
	CategoriesTools category;

#pragma region Getters
public:
	inline CategoriesTools GetCategory()const
	{
		return category;
	}
	inline u_int GetDamage()const
	{
		return damage;
	}
	inline string GetName()const
	{
		return name;
	}
#pragma endregion

#pragma region Constructor
public:
	Tool(const string& _name, cu_int& _damage, const CategoriesTools& _category);
#pragma endregion
};

