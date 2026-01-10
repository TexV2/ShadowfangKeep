#include "Enemy.h"
Enemy::Enemy(const std::string& name, int hp, int attack, int defense)
	: Entity(name, hp, attack, defense)
{
}
Enemy::~Enemy()
{
}
void Enemy::takeTurn(Player& player)
{
	int damageDealt = dealDamage();
	std::cout << name << " attacks " << player.getName() << " for " << damageDealt << " damage!\n";
}
// Info
std::string Enemy::toString()
{
	return "Enemy:\n" + Entity::toString();
}
