#include "CharacterMenu.h"
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
	std::cout << "1. View Character Stats" << std::endl;
	std::cout << "2. Equip Items" << std::endl;
	std::cout << "3. Back to Main Menu" << std::endl;
}
MenuAction CharacterMenu::getUserChoice()
{
	//Placeholder Implementation
	return MenuAction::None;
}