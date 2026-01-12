#pragma once
#include "Menu.h"

class ExplorationMenu : public baseMenu
{
private:
public:
	ExplorationMenu();
	~ExplorationMenu() override;
	void displayOptions() override;
	MenuAction getUserChoice() override;
};