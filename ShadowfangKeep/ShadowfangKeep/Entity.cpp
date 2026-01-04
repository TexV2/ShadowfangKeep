#include "Entity.h"
#include "Algorithm"
#include <iostream>

Entity::Entity(const std::string& name, int hp, int damage, int defense)
{
	this->name = name;
	this->maxHP = hp;
	this->attack = damage;
	this->defense = defense;
}
Entity::~Entity()
{
}
//Combat
int Entity::takeDamage(int rawDamage)
{
	int damageTaken = std::max(0, rawDamage - defense);
	currentHP -= damageTaken;
	if (currentHP < 0)
		currentHP = 0;
	return damageTaken;
}
int Entity::dealDamage() const
{
	return attack;
}
bool Entity::isAlive() const
{
	return currentHP > 0;
}
//Info
std::string Entity::toString()
{
	return "Name: " + name + "\nHP: " + std::to_string(currentHP) + "/" + std::to_string(maxHP) + "\nAttack: " + std::to_string(attack) + "\nDefense: " + std::to_string(defense);
}
//Getters
const std::string Entity::getName() const
{
	return name;
}
int Entity::getHP() const
{
	return currentHP;
}
int Entity::getDefense() const
{
	return defense;
}
int Entity::getAttack() const
{
	return attack;
}
int Entity::getMaxHp() const
{
	return maxHP;
}