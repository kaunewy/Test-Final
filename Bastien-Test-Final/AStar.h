#pragma once
#include "Macro.h"
#include <vector>
#include <queue>
#include "Position.h"
#include <cmath>


struct Node
{
	u_int x;
	u_int y;

	u_int costFromStart;
	u_int totalCost;

	Node* parent;

	Node(u_int _x, u_int _y, u_int _costFromStart = 0, u_int _totalCost = 0, Node* _parent = nullptr)
	{
		x = _x;
		y = _y;
		costFromStart = _costFromStart;
		totalCost = _totalCost;
		parent = _parent;
	}

	bool operator > (const Node& _other) const
	{
		return totalCost > _other.totalCost;
	}
};

template <typename Type>
class AStar
{
	vector<vector<Type>> map;
	Position start;
	Position goal;
	
#pragma region Constructor
public:
	AStar(vector<vector<Type>> _map, Position _start, Position _goal)
	{
		map = _map;
		start = _start;
		goal = _goal;
	}
	~AStar()
	{

	}
#pragma endregion

#pragma region Function
public:
	u_int Heuristic(int _x1, int _y1, int _x2, int _y2)
	{
		return abs(_x1 - _x2) + abs(_y1 - _y2);
	}

	bool IsValid(u_int _x, u_int _y, const vector<vector<Type>>& _map)
	{
		return _x >= 0 && _y >= 0 && _x < _map.size() && _y < _map[0].size();
	}

	vector<Position> AStarFunction()
	{
		priority_queue<Node, vector<Node>, greater<Node>> _openList;

		vector<vector<bool>> _closedList(map.size(), vector<bool>(map[0].size(), false));

		_openList.emplace(start.x, start.y, 0, Heuristic(start.x, start.y, goal.x, goal.y));
		vector<Node*> _toDelete;
		while (!_openList.empty())
		{
			Node _current = _openList.top();
			
			_toDelete.push_back(_current.parent);
			_openList.pop();

			if (_current.x == goal.x && _current.y == goal.y)
			{
				vector<Position> _path;
				Node* _node = &_current;
				while (_node)
				{
					_path.emplace_back(_node->x, _node->y);
					_node = _node->parent;
				}
				//reverse(_path.begin(), _path.end());
				while (!_openList.empty())
				{
					Node _temp = _openList.top();
					delete _temp.parent;
					_openList.pop();
				}
				for (Node *_node : _toDelete)
				{
					cout << _toDelete.size() << endl;
					delete _node;
					cout << "feur" << endl;
				}
				return _path;
			}
			if (_closedList[_current.x][_current.y]) continue;
			_closedList[_current.x][_current.y] = true;

			vector<Position> _directionTab = { Position(-1,0),Position(1,0),Position(0,-1), Position(0,1) };

			for (const auto _direction : _directionTab)
			{
				u_int _newX = _current.x + _direction.x;
				u_int _newY = _current.y + _direction.y;

				if (IsValid(_newX, _newY, map) && !_closedList[_newX][_newY])
				{
					u_int _costFromStart = _current.costFromStart + 1;
					u_int _heuristic = Heuristic(_newY, _newY, goal.x, goal.y);
					_openList.emplace(_newX, _newY, _costFromStart, _costFromStart + _heuristic, new Node(_current));
				}
			}
		}
		return {};
	}
#pragma endregion

};

