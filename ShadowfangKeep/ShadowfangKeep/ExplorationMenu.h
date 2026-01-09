#pragma once
#include "Menu.h";

class ExplorationMenu : public baseMenu
{
private:
	bool isRoomEmpty;
public:
	ExplorationMenu(bool isRoomEmpty);
	~ExplorationMenu() override;
	void displayOptions() override;
	MenuAction getUserChoice() override;
};