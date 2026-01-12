#include "CombatSystem.h"

CombatSystem::CombatSystem(Player& player, Enemy& enemy)
	:player(player), enemy(enemy)
{
}

CombatSystem::~CombatSystem()
{
}

void CombatSystem::startCombat()
{
}
