#include "Game.h"


void Game::GameLoop()
{
	Colony _colony;

	_colony.AddDwarf("pute", Dwarf());
	_colony.GetDwarfs()[0].second->AddTool(Tool("zizi", 20, CT_BUCKET));

	Map _map(60, 40, _colony);

	_colony.AddDwarf("salope", Dwarf(J_HUNTER,100, Position(22,22)));

	_map.Init();
	while (true)
	{
		MoveDwarf(_colony, _map);
		_map.Display();
		for (auto _resource : _colony.GetResources())
		{
			cout << _colony.GetNameByResource(_resource.first) << " : " << _resource.second << endl;
		}
		_map.Move();
		system("cls");
	}
}

void Game::MoveDwarf(Colony& _colony, const Map& _map)
{
	for (auto _dwarf : _colony.GetDwarfs())
	{
		Position _goal = Position(_dwarf.second->GetPos());
		int _minDist = INT_MAX;
		for (u_int _i = 0; _i < _map.GetLength(); _i++)
		{
			for (u_int _j = 0; _j < _map.GetWidth(); _j++)
			{
				int _dist = abs(int(_dwarf.second->GetPos().x) - int(_i)) + abs(int(_dwarf.second->GetPos().y) - int(_j));
				if (_dist < _minDist && _map.GetMap()[_i][_j] == _dwarf.second->GetDwarfJob())
				{
					_minDist = _dist;
					_goal = Position(_i, _j);
				}
			}
		}
		_dwarf.second->FindPath(_goal, _map.GetMap());
		_dwarf.second->Move();
		_colony.AddToResource(*_dwarf.second, _map.GetMap()[_dwarf.second->GetPos().x][_dwarf.second->GetPos().y]);
	}
}
