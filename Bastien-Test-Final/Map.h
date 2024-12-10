#pragma once
#include "Macro.h"
#include <vector>
#include "Random.h"
#include "Position.h"
#include "TileType.h"

class Map
{
	vector<vector<TileType>> map;
	Position cursorPlayer;
	u_int width;
	u_int length;

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
#pragma endregion

#pragma region Constructor
public:
	Map() = default;
	Map(cu_int& _width, cu_int& _length);
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

