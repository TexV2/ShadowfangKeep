#include "Worldbuilder.h"
#include "EmptyRoom.h"
#include "EnemyRoom.h"
#include "Werewolf.h"
#include "LootRoom.h"
#include "Helmet.h"
#include <memory> // Add this include for std::unique_ptr

std::vector<std::unique_ptr<Room>> Worldbuilder::buildWorld()
{
	// Create Rooms
	rooms.push_back(std::make_unique<EmptyRoom>("You enter a dimly lit hallway", "There is a door to the north.", "r1"));
	rooms.push_back(std::make_unique<EnemyRoom>("You open the door and enter a twisted corridor.", "On the left side of the corridor there is an open door.", "r2", std::make_unique<Werewolf>()));
	Helmet* helmet = new Helmet("Bronze Helmet", "A sturdy helmet forged from bronze", 5);
	rooms.push_back(std::make_unique<LootRoom>("You enter a ominous dungeon cell with a chest in the middle", "On the floor there is a trapdoor.", "r3", helmet));
	
	rooms.push_back(std::make_unique<EmptyRoom>("You enter a storage cellar", "There is a hole in the wall leading into darkness", "r4"));
	return std::move(rooms);
}