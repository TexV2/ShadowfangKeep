#include "ExplorationMenu.h"
#include <iostream>
ExplorationMenu::ExplorationMenu(bool isRoomEmpty)
{
	this->isRoomEmpty = isRoomEmpty;
}
ExplorationMenu::~ExplorationMenu()
{
}
void ExplorationMenu::displayOptions()
{
	std::cout << "Exploration Menu:\n";
	std::cout << "1. Continue\n";
	if (isRoomEmpty = false)
	{
		std::cout << "2. Search the room\n";
	}
	std::cout << "3. View Inventory\n";
	std::cout << "q. Menu\n";
}

MenuAction ExplorationMenu::getUserChoice()
{
	char choice;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	switch (choice)
	{
	case '1':
		return MenuAction::CONTINUE;
	case '2':
		if (isRoomEmpty = false)
		{
			return MenuAction::SEARCH_ROOM;
		}
		else
		{
			std::cout << "Invalid choice. Please try again.\n";
			return getUserChoice();
		}
	case '3':
		return MenuAction::OPEN_INVENTORY;
	case 'q':
		return MenuAction::OPEN_MENU;
	default:
		std::cout << "Invalid choice. Please try again.\n";
		return getUserChoice();
	}
}
