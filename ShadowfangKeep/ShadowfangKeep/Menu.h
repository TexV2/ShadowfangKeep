#pragma once
enum class MenuAction {
    None,
	//Main Menu Actions
    BACK,
    EXIT_GAME,
    START_NEW_GAME,
    LOAD_GAME,
    OPEN_INVENTORY,
    OPTIONS,
	//Character Selection Actions
    WARRIOR,
    RANGER
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