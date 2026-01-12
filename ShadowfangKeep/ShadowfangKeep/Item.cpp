#include "Item.h"
#include "Player.h"
Item::Item(const std::string& name, const std::string& description, int slot)
{
	this->name = name;
	this->description = description;
	this->slot = slot;
}
Item::~Item()
{
}
std::string Item::getName() const
{
	return name;
}
std::string Item::getDescription() const
{
	return description;
}

int Item::getSlot() const
{
	return slot;
}