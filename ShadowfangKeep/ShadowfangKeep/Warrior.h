#pragma once
#include "Player.h"
class Warrior : public Player
{
	public:
	Warrior(const std::string& name);
	~Warrior();
	virtual std::string toString() override;
};