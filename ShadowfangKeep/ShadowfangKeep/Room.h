#pragma once
#include "Player.h"
#include <vector>
using std::vector;
class Room
{
private:
	std::string description;
	bool hasEnemy;
	vector <Room> paths;
public:
	Room();
	~Room();
	void Encouter(Player* p);
	Room choosePath(int i);
	private:
};