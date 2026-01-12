#include "Room.h"
#include "Game.h"
Room::Room(std::string EntryDescription, std::string ExitDescription, std::string name, bool hasEnemy)
{
	this->visited = false;
	this->isRoomEmpty = false;
	this->name = name;
	this->hasEnemy = hasEnemy;
	this->descriptionEntry = EntryDescription;
	this->descriptionExit = ExitDescription;
}
Room::~Room()
{
}
std::string Room::getEntry()
{
	return descriptionEntry;
	this->visited = true;
}
std::string Room::getExit()
{
	return descriptionExit;
}
bool Room::getVisited() const
{
	return this->visited;
}

void Room::setVisited(bool visited)
{
	this->visited = visited;
}

bool Room::getIsRoomEmpty() const
{
	return isRoomEmpty;
}
void Room::setIsRoomEmpty(bool isEmpty)
{
	this->isRoomEmpty = isEmpty;
}
bool Room::getHasEnemy() const
{
	return this->hasEnemy;
}

void Room::setHasEnemy(bool hasEnemy)
{
	this->hasEnemy = hasEnemy;
}
