#include "Game.h"


void Game::GameLoop()
{
	Colony _colony;

	_colony.AddDwarf("pute", Dwarf());
	_colony.GetDwarfs()[0].second->AddTool(Tool("zizi", 20, CT_BUCKET));

	Map _map(60, 40, _colony);

	_colony.AddDwarf("salope", Dwarf(J_HUNTER,100, Position(22,22)));
	_colony.GetDwarfs()[1].second->AddTool(Tool("zizi", 20, CT_SWORD));

	_map.AddHouse(House(TH_BIG, Position(_map.GetLength() / 2, _map.GetWidth() / 2)));

	_map.AddEnemy(new Giant(NONE, 150, 40,  Position(_map.GetLength() / 2 + 5, _map.GetWidth() / 2 + 5), "Pierre"));

	_map.Init();
	while (true)
	{
		MoveDwarfs(_colony, _map);
		MoveEnemies(_map);
		_map.Display();
		for (auto _resource : _colony.GetResources())
		{
			cout << _colony.GetNameByResource(_resource.first) << " : " << _resource.second << endl;
		}
		_map.Move();
		this_thread::sleep_for(chrono::milliseconds(16));
		system("cls");
	}
}

void Game::MoveDwarfs(Colony& _colony, const Map& _map)
{
	for (auto _dwarf : _colony.GetDwarfs())
	{
		if(_dwarf.second->GetMovement().empty())
		{
			Position _goal = Position(_dwarf.second->GetPos());
			int _minDist = INT_MAX;
			for (u_int _i = 0; _i < _map.GetLength(); _i++)
			{
				for (u_int _j = 0; _j < _map.GetWidth(); _j++)
				{
					int _dist = abs(int(_dwarf.second->GetPos().x) - int(_i)) + abs(int(_dwarf.second->GetPos().y) - int(_j));
					if (_dist < _minDist && _map.GetMap()[_i][_j].first == _dwarf.second->GetDwarfJob())
					{
						_minDist = _dist;
						_goal = Position(_i, _j);
					}
				}
			}
			_dwarf.second->FindPath(_goal, _map.GetMap());
		}
		_dwarf.second->Move();
		_colony.AddToResource(*_dwarf.second, _map.GetMap()[_dwarf.second->GetPos().x][_dwarf.second->GetPos().y].first);
	}
}

void Game::MoveEnemies(Map& _map)
{
	for (auto _enemy : _map.GetEnemies())
	{
		if (_enemy->GetMovement().empty())
		{
			Position _goal = Position(_enemy->GetPos());
			int _minDist = INT_MAX;
			for (u_int _i = 0; _i < _map.GetLength(); _i++)
			{
				for (u_int _j = 0; _j < _map.GetWidth(); _j++)
				{
					int _dist = abs(int(_enemy->GetPos().x) - int(_i)) + abs(int(_enemy->GetPos().y) - int(_j));
					if (_dist < _minDist && _map.GetMap()[_i][_j].second == OT_DWARF)
					{
						_minDist = _dist;
						_goal = Position(_i, _j);
					}
				}
			}
			_enemy->FindPath(_goal, _map.GetMap());
		}
		_enemy->Move();
	}
}
