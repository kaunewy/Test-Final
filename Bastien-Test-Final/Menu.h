#pragma once
#include "Macro.h"
#include <vector>
#include <conio.h>
class Menu
{
	vector<pair<string, void(*)()>> options;

#pragma region Constructor
public:
	Menu() = default;
	Menu(vector<pair<string, void(*)()>> _options);
#pragma endregion

#pragma region Functions
	void Choice();
	virtual void Display();
#pragma endregion
};

