#pragma once
#include "Room.h"
#include "Item.h"
#include <iostream>
class LootRoom : public Room
{
private:
	Item* loot;
public:
	LootRoom(std::string entryDescription, std::string exitDescription, std::string name, Item* item);
	~LootRoom() override;
	void enter(Player& player) override;
	void searchRoom(Player& player);
};