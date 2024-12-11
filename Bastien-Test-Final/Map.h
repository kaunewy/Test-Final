#pragma once
#include "Macro.h"
#include <vector>
#include "Random.h"
#include "Position.h"
#include "TileType.h"
#include "Colony.h"
#include "Menu.h"

class Map
{
	vector<vector<TileType>> map;
	Position cursorPlayer;
	u_int width;
	u_int length;
	Colony* colony;
	vector<Menu> menu;
	Menu _currentMenu;

#pragma region Getters
public:
	inline vector<vector<TileType>> GetMap() const
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
#pragma endregion
};

