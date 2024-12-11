#pragma once
#include "Macro.h"
#include <vector>
#include <conio.h>
#include <functional>
class Menu
{
	vector<pair<string, function<void()>>> options;
	int currentIndex;

#pragma region Constructor
public:
	Menu();
#pragma endregion

#pragma region Functions
	void Choice();
	void Display();
	void AddOption(const string& _name, function<void()> _action);
#pragma endregion
};

