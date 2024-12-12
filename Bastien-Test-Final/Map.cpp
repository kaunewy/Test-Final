#include "Map.h"

Map::Map(cu_int& _width, cu_int& _length, Colony& _colony)
{
	width = _width;
	length = _length;
	colony = &_colony;
	cursorPlayer = Position(length/2,width/2);
}



void Map::Init()
{
	static const Position _direction[] = { Position(-1,0),Position(0,-1)};
	
	for (u_int _i = 0; _i < length; _i++)
	{
		vector<TileType> _tabTile;
		map.push_back(vector<pair<TileType, ObjectType>>());
		for (u_int _j = 0; _j < width; _j++)
		{
			_tabTile.push_back(GetTile(Position(_i,_j), _direction[0]));
			_tabTile.push_back(GetTile(Position(_i, _j), _direction[1]));
			_tabTile.push_back(static_cast<TileType>(GetRandomNumberInRange(0, COUNT - 1)));
			map[_i].push_back(make_pair(_tabTile[GetRandomNumberInRange(0,2)], OT_NONE));
		}
	}
}

void Map::Display()
{
	u_int _sizeMapDisplayT = cursorPlayer.x < 10 ? 10  - cursorPlayer.x : 0;
	u_int _sizeMapDisplayB = cursorPlayer.x > length - 10 ? 10 - ((cursorPlayer.x + 10) -length) : 0;
	u_int _sizeMapDisplayL = cursorPlayer.y < 10 ? 10 - cursorPlayer.y : 0;
	u_int _sizeMapDisplayR = cursorPlayer.y > width - 10 ? 10 - ((cursorPlayer.y + 10) - width) : 0;
	for (u_int _i = 0; _i < length; _i++)
	{
		for (u_int _j = 0; _j < width; _j++)
		{
			map[_i][_j].second = OT_NONE;
		}
	}
	for (u_int _i = cursorPlayer.x - (10 - _sizeMapDisplayT); _i < min<u_int>(length - 1,cursorPlayer.x + (10 - _sizeMapDisplayB)); _i++)
	{
		for (u_int _j = cursorPlayer.y - (10 - _sizeMapDisplayL); _j < min<u_int>(width - 1,cursorPlayer.y + (10 - _sizeMapDisplayR)); _j++)
		{ 
			u_int _addRGB = 0;
			if (cursorPlayer.x == _i && cursorPlayer.y == _j)
			{
				_addRGB = 50;
			}
			for (const auto _dwarf : colony->GetDwarfs())
			{
				if (_dwarf.second->GetPos().x == _i && _dwarf.second->GetPos().y == _j)
				{
					cout << BG_RGB(140 + _addRGB, 52, 52) << " " << COLORRESET;
					map[_i][_j].second = OT_DWARF;
				}
				continue;
			}

			for (const auto _house : houses)
			{
				if(_house.GetPos().x == _i && _house.GetPos().y == _j)
				{
					cout << BG_RGB(150 + _addRGB, 0, 0) << " " << COLORRESET;
					map[_i][_j].second = OT_BUILDING;
				}
				continue;
			}
			for (const auto _enemy : enemies)
			{
				if (_enemy->GetPos().x == _i && _enemy->GetPos().y == _j)
				{
					cout << BG_RGB(0 + _addRGB, 0 + _addRGB, 0 + _addRGB) << " " << COLORRESET;
					map[_i][_j].second = map[_i][_j].second == OT_DWARF ? OT_DWARF : OT_ENEMY;
				}
				continue;
			}
			switch (map[_i][_j].first)
			{
			case WOOD:
				cout << BG_RGB(0, 60 + _addRGB, 0) << " " << COLORRESET;
				break;
			case STONE:
				cout << BG_RGB(125 + _addRGB, 125 + _addRGB, 125 + _addRGB) << " " << COLORRESET;
				break;
			case WATER:
				cout << BG_RGB(0, 0, 150 + _addRGB) << " " << COLORRESET;
				break;
			case FOOD:
				cout << BG_RGB(150 + _addRGB, 150 + _addRGB, 0) << " " << COLORRESET;
				break;
			default:
				cout << BG_RGB(0, 200 + _addRGB, 0) << " " << COLORRESET;
				break;
			}
		}
		cout << endl;
	}
}

void Map::Move()
{
	static const Position _directionTab[] = { Position(-1,0),Position(1,0),Position(0,-1), Position(0,1)};
	Position _direction;
	if(_kbhit())
	{
		u_int _key = _getch();
		switch (_key)
		{
		case 72:
			_direction = _directionTab[0];
			break;
		case 80:
			_direction = _directionTab[1];
			break;
		case 75:
			_direction = _directionTab[2];
			break;
		case 77:
			_direction = _directionTab[3];
			break;
		case 32:
			if (map[cursorPlayer.x][cursorPlayer.y].second == OT_DWARF)
			{
			system("pause");
				for (auto _dwarf : colony->GetDwarfs())
				{
					if (_dwarf.second->GetPos().x == cursorPlayer.x && _dwarf.second->GetPos().y == cursorPlayer.y)
					{
						InitMenuDwarf(*_dwarf.second);
					}
				}
			}
			if (map[cursorPlayer.x][cursorPlayer.y].second == OT_BUILDING)
			{
				system("pause");
				for (auto _house : houses)
				{
					if (_house.GetPos().x == cursorPlayer.x && _house.GetPos().y == cursorPlayer.y)
					{
						InitMenuHouse(_house);
					}
				}
			}
			break;
		default:
			_direction = Position(0, 0);
			break;
		}
		if (IsValid(cursorPlayer, _direction))
		{
			cursorPlayer = Position(cursorPlayer.x + _direction.x, cursorPlayer.y + _direction.y);
		}
	}
}

bool Map::IsValid(Position _currentPos, Position _direction) const
{
	Position _newPos = Position(_currentPos.x + _direction.x, _currentPos.y + _direction.y);
	if (_newPos.x >= 0 && _newPos.y >= 0 && _newPos.x <= length && _newPos.y <= width)
	{
		return true;
	}
	return false;
}

TileType Map::GetTile(Position _currentPos, Position _direction)
{
	Position _newPos = Position(_currentPos.x + _direction.x, _currentPos.y + _direction.y);
	if (IsValid(_currentPos, _direction))
	{
		return map[_newPos.x][_newPos.y].first;
	}
	return NONE;
}

void Map::InitMenuDwarf(Dwarf& _dwarf)
{
	Menu _dwarfMenu;
	system("cls");
	cout << "Life : " << _dwarf.GetSatiaty() << "| Job : " << _dwarf.GetJobName(_dwarf.GetDwarfJob()) << endl;
	_dwarfMenu.AddOption("Changer métier", [&_dwarf] {_dwarf.ChangeJob();});
	_dwarfMenu.AddOption("Nourrir", [this, &_dwarf] {colony->Feed(_dwarf);});
	system("pause");
	_dwarfMenu.Choice();
}

void Map::InitMenuHouse(House& _house)
{
	Menu _houseMenu;
	system("cls");
	cout << "Nombre de nains : " << _house.GetDwarfsInHouse().size() << endl;
	system("pause");
	//_houseMenu.Choice();
}

void Map::AddHouse(const House& _house)
{
	houses.push_back(_house);
}

void Map::AddEnemy(Enemy* _enemy)
{
	enemies.push_back(_enemy);
}
