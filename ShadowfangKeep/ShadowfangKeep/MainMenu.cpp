#include "MainMenu.h"
#include <iostream>
MainMenu::MainMenu() : baseMenu()
{
}
MainMenu::~MainMenu()
{
}
void MainMenu::displayOptions()
{
	std::cout << "=== Main Menu ===" << std::endl;
	std::cout << "1. Start New Game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Options" << std::endl;
	std::cout << "4. Exit" << std::endl;
}
MenuAction MainMenu::getUserChoice()
{
	int choice;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	if (choice == 1)
	{
		return MenuAction::START_NEW_GAME;
	}
	else if (choice == 2)
	{
		return MenuAction::LOAD_GAME;
	}
	else if (choice == 3)
	{
		return MenuAction::OPTIONS;
	}
	else if (choice == 4)
	{
		return MenuAction::EXIT_GAME;
	}
	else
	{
		std::cout << "Invalid choice. Please try again." << std::endl;
		getUserChoice();
	}
}
