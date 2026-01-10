#pragma once
#include "Player.h"
#include <vector>
using std::vector;
class Room
{
private:
	std::string descriptionEntry;
	std::string descriptionExit;
	std::string name;
	bool visited;
	bool isRoomEmpty;
	
public:
	Room(std::string EntryDescription, std::string ExitDescription, std::string name);
	virtual ~Room() = 0;
	virtual void enter(Player& player) = 0;
	virtual std::string getEntry();
	virtual std::string getExit();

	bool getIsRoomEmpty() const;
	void setIsRoomEmpty(bool isEmpty);
};