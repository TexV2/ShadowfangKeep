#include "Room.h"
Room::Room()
{
	description = "A dark and eerie room.";
	hasEnemy = false;
}
Room::~Room()
{
}
void Room::Encouter(Player* p)
{
	// Placeholder for encounter logic
	if (hasEnemy)
	{
		std::cout << "An enemy appears!" << std::endl;
		// Combat logic would go here
	}
	else
	{
		std::cout << "The room is empty." << std::endl;
	}
}
Room Room::choosePath(int i)
{
	if (i >= 0 && i < paths.size())
	{
		return paths[i];
	}
	else
	{
		std::cout << "Invalid path choice." << std::endl;
		return *this; // Return current room if invalid
	}
}
