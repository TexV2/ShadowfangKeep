#include "CharacterMenu.h"
#include "Warrior.h"
#include <cctype>
#include <iostream>
CharacterMenu::CharacterMenu() : baseMenu()
{
}
CharacterMenu::~CharacterMenu()
{
}
void CharacterMenu::displayOptions()
{
	std::cout << "=== Character Menu ===" << std::endl;
	std::cout << "1. Warrior" << std::endl;
}
MenuAction CharacterMenu::getUserChoice()
{
	int choice;
	std::cout << "Choose your class: ";
	while (true)
	{
		std::cin >> choice;
		if (choice == 1)
		{
			Warrior playerCharacter("...");
			std::cout << "You have selected the Warrior class!" << std::endl;
			std::cout << "Warrior Stats:" << std::endl;
			std::cout << playerCharacter.printArt() << std::endl;
			std::cout << playerCharacter.toString() << std::endl;
			std::cout << "Confirm selection? (y/n): ";
			char confirm;
			std::cin >> confirm;

			if (tolower(confirm) == 'y')
			{
				return MenuAction::WARRIOR;
			}
			else
			{
				return getUserChoice();
			}
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}
	
}