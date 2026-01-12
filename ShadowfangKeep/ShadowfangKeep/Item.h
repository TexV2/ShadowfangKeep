#pragma once
#include <string>

class Player;
class Item
{
private:
	std::string name;
	std::string description;
	int slot;
public:
	Item(const std::string& name, const std::string& description, int slot);
	virtual ~Item();
	std::string getName() const;
	std::string getDescription() const;
	int getSlot() const;

	virtual void equipItem(Player& player) {}
	virtual void unequipItem(Player& player) {}

};