#pragma once
#include "Entity.h"
#include "Player.h"
class Enemy : public Entity
{
private:
	std::string description;

public:
	Enemy(std::string description, std::string name, int hp, int attack, int defense);
	virtual ~Enemy() = 0;

	void takeTurn(Player &player);
	// Info
	virtual std::string toString();
	std::string getDescription() const;
};