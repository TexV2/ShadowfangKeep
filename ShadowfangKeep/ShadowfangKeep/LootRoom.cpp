#include "LootRoom.h"
#include "Player.h"

LootRoom::LootRoom(std::string entryDescription,
    std::string exitDescription,
    std::string name,
    Item* item)
    : Room(entryDescription, exitDescription, name, false),
    loot(item)
{
    setIsRoomEmpty(false);
    setVisited(false);
    setHasEnemy(false);
}

LootRoom::~LootRoom()
{
    // Do NOT delete loot here if Player takes ownership in pickUpItem.
    // After pickup, LootRoom should no longer own it.
}

void LootRoom::enter(Player& player)
{
    std::cout << getEntry() << std::endl;
    std::cout << getExit() << std::endl;
}

void LootRoom::searchRoom(Player& player)
{

    std::cout << "You found a " << loot->getName() << "!" << std::endl;
    player.pickUpItem(loot);
    loot = nullptr;
    setIsRoomEmpty(true);
}

