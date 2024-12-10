#include "Map.h"
#include "AStar.h"


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SetConsoleOutputCP(65001);

	Map _map(40, 60);

	_map.Init();
	while (true)
	{
	_map.Display();
	_map.Move();
	system("cls");
	}

	vector<Position> movement;

	return 0;
}