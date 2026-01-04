#include "Player.h"
Player::Player(const std::string& name, int hp, int attack, int defense)
	: Entity(name, hp, attack, defense), level(1), experience(0)
{
}
//Experience and Leveling
void Player::gainExperience(int exp)
{
	experience += exp;
	if (experience >= level * 100) // Example leveling threshold
	{
		levelUp();
	}
}
 void Player::levelUp()
{
	level++;
	experience = 0;
	maxHP += 10; 
	attack += 2;
	defense += 1;
	currentHP = maxHP;
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