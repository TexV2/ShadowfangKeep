#include "Armor.h"
#include "Player.h"
class Player;
Armor::Armor(const std::string& name, const std::string& description, int defenseBonus, int slot)
	: Item(name, description, slot)
{
	this->defenseBoost = defenseBonus;
}
int Armor::getDefenseBoost() const
{
	return defenseBoost;
}
int Armor::getSlot() const
{
	return slot;
}

void Armor::equipItem(Player &player)
{
	player.alterDefense(defenseBoost);
	std::cout << player.getName() << " gained " << defenseBoost << " defense by equipping " << getName() << "!" << std::endl;
}

void Armor::unequipItem(Player &player)
{
	player.alterDefense(-defenseBoost);
	std::cout << player.getName() << " lost " << defenseBoost << " defense by unequipping " << getName() << "!" << std::endl;
}
