#include "Room.h"
Room::Room(std::string EntryDescription, std::string ExitDescription, std::string name) : visited(false)
{
	this->isRoomEmpty = false;
	this->name = name;
	this->descriptionEntry = EntryDescription;
	this->descriptionExit = ExitDescription;
}
Room::~Room()
{
}
std::string Room::getEntry()
{
	return descriptionEntry;
}
std::string Room::getExit()
{
	return descriptionExit;
}
bool Room::getIsRoomEmpty() const
{
	return isRoomEmpty;
}
void Room::setIsRoomEmpty(bool isEmpty)
{
	isRoomEmpty = isEmpty;
}