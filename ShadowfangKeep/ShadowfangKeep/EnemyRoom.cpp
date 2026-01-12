#include "EnemyRoom.h"
EnemyRoom::EnemyRoom(std::string entryDescription, std::string exitDescription, std::string name, std::unique_ptr<Enemy> enemy)
	: Room(entryDescription, exitDescription, name, true)
{
	this->enemy = std::move(enemy);
}
EnemyRoom::~EnemyRoom()
{
}
std::unique_ptr<Enemy> EnemyRoom::releaseEnemy()
{
	return std::move(enemy);
}
void EnemyRoom::enter(Player& player)
{
	std::cout << getEntry() << std::endl;
	if (this->getIsRoomEmpty() == true)
	{
		std::cout << "The room is eerily quiet. The enemy has been defeated." << std::endl;
		return;
	}
	else if (this->getHasEnemy() == true)
	{
		std::cout << enemy->getDescription() << " appears!" << std::endl;
	}
}
Enemy* EnemyRoom::getEnemy() const
{
	return enemy.get();
}