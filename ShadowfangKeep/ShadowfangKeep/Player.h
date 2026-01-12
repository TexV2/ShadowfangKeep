#pragma once
#include "Entity.h"
#include "Inventory.h"
class Player : public Entity
{
private:
	int level;
	int experience;
	int playerClass;
	Inventory<Item*> inventory;

public:
	Player(const std::string& name, int hp, int attack, int defense, int playerClass);
	virtual ~Player();
	//Inventory Management
	void pickUpItem(Item* item);
	void equipItem(const std::string& itemName, Player &player);
	void alterDefense(int amount);
	//Info
	virtual std::string toString();
	//Getters
	int getLevel() const;
	int getExperience() const;
	int getPlayerClass() const;
	std::string getInventoryItems() const;
};