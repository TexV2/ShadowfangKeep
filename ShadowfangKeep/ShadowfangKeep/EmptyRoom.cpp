#include "EmptyRoom.h"
#include "Player.h"
EmptyRoom::EmptyRoom(std::string entryDescription, std::string exitDescription, std::string name)
	: Room(entryDescription, exitDescription, name, false)
{
	Room::setIsRoomEmpty(true);
}
EmptyRoom::~EmptyRoom()
{
}
void EmptyRoom::enter(Player& player)
{
	std::cout << getEntry() << "\n";
	std::cout << getExit() << "\n";

}