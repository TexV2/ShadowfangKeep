#pragma once
#include "Player.h"
class Warrior : public Player
{
	public:
	Warrior(const std::string& name);
	~Warrior();
	virtual void levelUp() override;
	virtual std::string toString() override;
};