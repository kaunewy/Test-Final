#pragma once
#include "Macro.h"
#include <vector>
#include "Random.h"
#include "Colony.h"
#include "Menu.h"
#include "ObjectType.h"
#include "House.h"
#include "Enemy.h"

class Map
{
	vector<vector<pair<TileType, ObjectType>>> map;
	Position cursorPlayer;
	u_int width;
	u_int length;
	Colony* colony;
	vector<House> houses;
	vector<Menu> menu;
	vector<Enemy> enemies;
	 
#pragma region Getters
public:
	inline vector<vector<pair<TileType, ObjectType>>> GetMap() const
	{
		return map;
	}
	inline Position GetCursorPlayer() const
	{
		return cursorPlayer;
	}
	inline u_int GetWidth() const
	{
		return width;
	}
	inline u_int GetLength() const
	{
		return length;
	}
#pragma endregion

#pragma region Constructor
public:
	Map() = default;
	Map(cu_int& _width, cu_int& _length, Colony& _colony);
#pragma endregion

#pragma region Function
public:
	void Init();
	void Display();
	void Move();
	bool IsValid(Position _currentPos, Position _direction) const;
	TileType GetTile(Position _currentPos, Position _direction = Position(0,0));
	void InitMenuDwarf(Dwarf& _dwarf);
	void InitMenuHouse(House& _house);
	void AddHouse(const House& _house);
	void AddEnemy(const Enemy& _enemy);
#pragma endregion
};

