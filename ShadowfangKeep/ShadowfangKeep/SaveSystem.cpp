#include "SaveSystem.h"
#include "Game.h"
SaveSystem::SaveSystem(int roomIndex, bool isRoomEmpty, Player* player)
{
	this->player = player;
	this->lineIndex = 0;
	this->playerClass = 0;
	this->roomIndex = roomIndex;
	this->playerName = "";
	this->isRoomEmpty = isRoomEmpty;
}

SaveSystem::SaveSystem()
{
	this->lineIndex = 0;
	this->playerClass = 0;
	this->roomIndex = 0;
	this->playerName = "";
	this->isRoomEmpty = false;
	this->player = nullptr;
}
SaveSystem::~SaveSystem()
{
}
void SaveSystem::saveGame()
{
	saveFile.open("savefile.sav", std::ios::out);
	if (saveFile.is_open())
	{
		saveFile << roomIndex << "\n" << player->getName() << "\n" << player->getPlayerClass() << "\n" << isRoomEmpty;
	}
	saveFile.close();
}
Loading SaveSystem::loadGame()
{
	saveFile.open("savefile.sav", std::ios::in);
	if (saveFile.is_open())
	{
		std::string line;
		while (std::getline(saveFile, line))
		{
			if (lineIndex == 0)
			{
				roomIndex = std::stoi(line);
			}
			else if (lineIndex == 1)
			{
				playerName = line;
			}
			else if (lineIndex == 2)
			{
				playerClass = std::stoi(line);
			}
			else if (lineIndex == 3)
			{
				isRoomEmpty = (line == "1") ? true : false;
			}
			lineIndex++;
		}
		return { roomIndex, isRoomEmpty, playerName, playerClass };
	}
	saveFile.close();
}