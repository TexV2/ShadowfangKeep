#include "Player.h"
Player::Player(const std::string& name, int hp, int attack, int defense, int playerClass)
	: Entity(name, hp, attack, defense), level(1), experience(0)
{
	this->playerClass = playerClass;
}
Player::~Player()
{
	inventory.clearAndDelete();
}
void Player::pickUpItem(Item* item)
{
	this->inventory.add(item);
}
void Player::equipItem(const std::string& itemName, Player &player)
{
	int idx = inventory.getIndex(itemName);
	if (idx < 0) return;

	Item* item = inventory.get(static_cast<size_t>(idx));
	inventory.equip(item, *this);
}
void Player::alterDefense(int amount)
{
	this->defense += amount;
}
//Info
std::string Player::toString()
{
	return Entity::toString() + "\nLevel: " + std::to_string(level) + "\nExperience: " + std::to_string(experience) + "/" + std::to_string(level * 100);
}
//Getters
int Player::getLevel() const
{
	return level;
}
int Player::getExperience() const
{
	return experience;
}

int Player::getPlayerClass() const
{
	return playerClass;
}

std::string Player::getInventoryItems() const
{
	std::string itemList;
	for (size_t i = 0; i < inventory.size(); ++i)
	{
		itemList += inventory.get(i)->getName() + "\n";
	}
	return itemList;
}