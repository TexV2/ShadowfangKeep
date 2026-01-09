#pragma once
#include "Room.h"
#include <vector>
#include <memory>

class Worldbuilder
{
private:
	std::vector<std::unique_ptr<Room>> rooms;
public:
	 std::vector<std::unique_ptr<Room>> buildWorld();
};