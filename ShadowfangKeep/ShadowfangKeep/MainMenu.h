#pragma once
#include "Menu.h"

class MainMenu : public baseMenu
{
private:
public:
	MainMenu();
	virtual ~MainMenu();
	virtual void displayOptions() override;
	virtual MenuAction getUserChoice() override;
};