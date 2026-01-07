#pragma once
#include "Entity.h"
class Player : public Entity
{
	private:
	int level;
	int experience;
public:
	Player(const std::string& name, int hp, int attack, int defense);
	virtual ~Player() = default;
	//Experience and Leveling
	void gainExperience(int exp);
	virtual void levelUp();
	//Info
	virtual std::string toString();
	//Getters
	int getLevel() const;
	int getExperience() const;
};