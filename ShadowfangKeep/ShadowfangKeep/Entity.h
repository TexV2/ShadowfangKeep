#include <string>
#include <iostream>
#pragma once
class Entity
{
protected:
	std::string name;
	int maxHP;
	int currentHP;
	int defense;
	int attack;
public:
	Entity(const std::string& name, int hp, int attack, int defense);
	~Entity();
	//Combat
	virtual int takeDamage(int rawDamage);
	virtual int dealDamage() const;

	bool isAlive() const;

	//Info
	virtual std::string toString();

	//Getters
	const std::string getName() const;
	int getHP() const;
	int getDefense() const;
	int getAttack() const;
	int getMaxHp() const;
};