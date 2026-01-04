#pragma once
enum class MenuAction {
    None,
    BACK,
    EXIT_GAME,
    START_NEW_GAME,
    LOAD_GAME,
    OPEN_INVENTORY,
    OPTIONS
};

class baseMenu
{
private:

public:
	baseMenu();
	virtual ~baseMenu();
	virtual void displayOptions() = 0;
	virtual MenuAction getUserChoice() = 0;
};