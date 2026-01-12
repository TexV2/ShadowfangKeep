#include "Enemy.h"
Enemy::Enemy(std::string description,  std::string name, int hp, int attack, int defense)
	: Entity(name, hp, attack, defense)
{
	this->description = description;
}
Enemy::~Enemy()
{
}
void Enemy::takeTurn(Player& player)
{
	int damageDealt = dealDamage(player);
	std::cout << name << " attacks " << player.getName() << " for " << damageDealt << " damage!\n";
}
// Info
std::string Enemy::toString()
{
	return "Enemy:\n" + Entity::toString();
}

std::string Enemy::getDescription() const
{
	return description;
}	
