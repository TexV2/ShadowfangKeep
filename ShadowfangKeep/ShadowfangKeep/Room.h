#pragma once
#include <string>
#include <vector>

class Player; // forward declaration to reduce header coupling

class Room
{
private:
	std::string descriptionEntry;
	std::string descriptionExit;
	std::string name;
	bool visited;
	bool isRoomEmpty;
	bool hasEnemy;
	
public:
	Room(std::string EntryDescription, std::string ExitDescription, std::string name, bool hasEnemy);
	virtual ~Room() = 0;
	virtual void enter(Player& player) = 0;
	virtual std::string getEntry();
	virtual std::string getExit();

	bool getVisited() const;
	void setVisited(bool visited);

	bool getIsRoomEmpty() const;
	void setIsRoomEmpty(bool isEmpty);

	bool getHasEnemy() const;
	void setHasEnemy(bool hasEnemy);
};