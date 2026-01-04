#pragma once
#include "Player.h"
class Warrior : public Player
{
	public:
	Warrior(const std::string& name);
	~Warrior();
	// Override levelUp to provide Warrior-specific stat increases
	virtual void levelUp() override;
	// Info
	virtual std::string toString() override;
};