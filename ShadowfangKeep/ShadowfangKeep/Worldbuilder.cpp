#include "Worldbuilder.h"
#include "EmptyRoom.h"
#include <memory> // Add this include for std::unique_ptr

std::vector<std::unique_ptr<Room>> Worldbuilder::buildWorld()
{
	// Create Rooms
	rooms.push_back(std::make_unique<EmptyRoom>("You enter a dimly lit hallway", "There is a door to the north.", "r1"));
	rooms.push_back(std::make_unique<EmptyRoom>("You enter a dark and ominous cavern", "Before you stands a wicked looking door.", "r2"));
	rooms.push_back(std::make_unique<EmptyRoom>("You enter a ominous dungeon cell", "On the floor there is a trapdoor.", "r3"));
	rooms.push_back(std::make_unique<EmptyRoom>("You enter a storage cellar", "There is a hole in the wall leading into darkness", "r3"));
	return std::move(rooms);
}