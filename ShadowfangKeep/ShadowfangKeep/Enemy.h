#pragma once
#include "Entity.h"
#include "Player.h"
class Enemy : public Entity
{
private:

public:
	Enemy(const std::string& name, int hp, int attack, int defense);
	virtual ~Enemy() = 0;

	void takeTurn(Player &player);
	// Info
	virtual std::string toString();
};