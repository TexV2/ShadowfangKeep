#pragma once
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
class CombatSystem
{
	private:
	Player& player;
	Enemy& enemy;
	public:
		CombatSystem(Player& player, Enemy& enemy);
		~CombatSystem();
		void startCombat();
};