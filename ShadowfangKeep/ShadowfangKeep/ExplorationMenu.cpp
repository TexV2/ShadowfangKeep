#include "ExplorationMenu.h"
#include <iostream>
ExplorationMenu::ExplorationMenu()
{
}
ExplorationMenu::~ExplorationMenu()
{
}
void ExplorationMenu::displayOptions()
{
	std::cout << "Exploration Menu:\n";
	std::cout << "1. Continue\n";
	std::cout << "2. Search the room\n";
	std::cout << "3. View Inventory\n";
	std::cout << "4. Save\n";
	std::cout << "q. Quit\n";
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
		return MenuAction::SEARCH_ROOM;
	case '3':
		return MenuAction::OPEN_INVENTORY;
	case '4':
		return MenuAction::SAVE_GAME;
	case 'q':
		return MenuAction::EXIT_GAME;
	default:
		std::cout << "Invalid choice. Please try again.\n";
		return getUserChoice();
	}
}
