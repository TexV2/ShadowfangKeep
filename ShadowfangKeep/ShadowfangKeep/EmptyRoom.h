#include "Room.h"
#pragma once

class EmptyRoom : public Room
{
public:
	EmptyRoom(std::string entryDescription, std::string exitDescription, std::string name);
	~EmptyRoom() override;
	virtual void enter(Player& player) override;
private:
};