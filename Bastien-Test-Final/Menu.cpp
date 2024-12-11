#include "Menu.h"

Menu::Menu()
{
    currentIndex = 0;
}

void Menu::Choice()
{
    bool _leaveMenu = false;
    while (!_leaveMenu) {
        Display();
        int _key = _getch();

        switch (_key)
        {
        case 72:
            if (currentIndex == 0)
            {
                currentIndex = int(options.size()) - 1;
            }
            else
            {
                --currentIndex;
            }
            break;
        case 80:
            if (currentIndex == options.size() -1)
            {
                currentIndex = 0;
            }
            else
            {
                ++currentIndex;
            }
            break;
        case 13:
            system("cls");
            options[currentIndex].second();
            system("pause");
            break;
        case 27:
            _leaveMenu = true;
            break;
        default:
            break;
        }
    }
}

void Menu::Display()
{
    system("cls");
    cout << "\n===== Menu =====\n";
    for (size_t i = 0; i < options.size(); ++i) {
        if (i == currentIndex)
            cout << " -> " << options[i].first << " <-\n";
        else
            cout << "   " << options[i].first << "\n";
    }
}

void Menu::AddOption(const string& _name, function<void()> _action)
{
    options.emplace_back(_name, _action);
}
