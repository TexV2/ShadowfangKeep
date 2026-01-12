#pragma once
#include <memory>
#include "Room.h"
#include <vector>
#include "Worldbuilder.h"
#include "Enemy.h"
#include "SaveSystem.h"
enum class GameState
{
	MAIN_MENU,
	CHARACTERSELECTION,
	EXPLORATION,
	PAUSED,
	COMBAT,
	GAME_OVER
};

class Player;

class Game
{
private:
	Worldbuilder worldBuilder;
	std::vector<std::unique_ptr<Room>> rooms;
	GameState currentState;
	std::unique_ptr<Player> player;
	std::unique_ptr<Enemy> currentEnemy;
	std::unique_ptr<SaveSystem> saveSystem;
	int currentRoomIndex = 0;
public:
	/*Management*/
	Game();
	~Game();
	void Start();
	void Update();
	void Shutdown();
	void ChangeState(GameState newState);
	GameState getState() const;
	int getIndex() const;
	bool getIsRoomEmpty() const;
	void setIsRoomEmpty(bool isEmpty);
	void setIndex(int index);
	void makePlayer(std::string name, int playerClass);
	void saveGame();
	void loadGame();

	//Menus
	//Main Menu
	void updateMainMenu();
	void updatePause();
	void updateCharacterSelection();
	void openInventory();
	
	/*Gameplay*/
	//Exploration
	void updateExploration();
	void searchRoom(Room* currentRoom);

	//Combat
	void updateCombat();


};