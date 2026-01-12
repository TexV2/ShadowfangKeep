#pragma once
#include "Item.h"
class Armor : public Item
{
private:
	int defenseBoost;
	int slot;
public:
	Armor(const std::string& name, const std::string& description, int defenseBoost, int slot);
	~Armor() override = default;
	int getDefenseBoost() const;
	int getSlot() const;
	void equipItem(Player &player) override;
	void unequipItem(Player &player) override;
};