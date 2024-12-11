#include "Game.h"


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SetConsoleOutputCP(65001);

	Game _game;

	_game.GameLoop();


	return 0;
}