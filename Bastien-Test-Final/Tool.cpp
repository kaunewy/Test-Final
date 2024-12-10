#include "Tool.h"

Tool::Tool(const string& _name, cu_int& _damage, const CategoriesTools& _category)
{
	name = _name;
	damage = _damage;
	category = _category;
}
