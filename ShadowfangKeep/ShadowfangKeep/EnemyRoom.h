#pragma once
#include "Room.h"
#include "Enemy.h"
class EnemyRoom : public Room
{
	private:
		std::unique_ptr<Enemy> enemy;
public:
		EnemyRoom(std::string entryDescription, std::string exitDescription, std::string name, std::unique_ptr<Enemy> enemy);
		~EnemyRoom() override;

		std::unique_ptr<Enemy> releaseEnemy();
		virtual void enter(Player& player) override;
		Enemy* getEnemy() const;
};