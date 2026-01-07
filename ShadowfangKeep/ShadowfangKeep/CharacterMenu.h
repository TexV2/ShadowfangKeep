#pragma once
#include "Menu.h"

class CharacterMenu : public baseMenu
{
private:
public:
	CharacterMenu();
	virtual ~CharacterMenu();
	virtual void displayOptions() override;
	virtual MenuAction getUserChoice() override;
};

