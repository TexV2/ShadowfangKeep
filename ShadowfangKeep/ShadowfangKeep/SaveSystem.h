#pragma once
#include <fstream>
#include "Player.h"

struct Loading
{
	int roomIndex;
	bool isRoomEmpty;
	std::string playerName;
	int playerClass;
};

class SaveSystem
{
private:
	std::fstream saveFile;
	Player* player;
	int lineIndex;
	int playerClass;
	int roomIndex;
	bool isRoomEmpty;
	std::string playerName;
public:
	SaveSystem(int roomIndex, bool isRoomEmpty, Player* player);
	SaveSystem();
	~SaveSystem();
	void saveGame();
	Loading loadGame();
};