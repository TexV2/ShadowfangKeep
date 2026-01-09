#pragma once
#include <memory>
#include "Room.h"
#include <vector>
#include "Worldbuilder.h"
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
	int currentRoomIndex = 1;
public:
	/*Management*/
	Game();
	~Game();
	void Start();
	void Update();
	void Shutdown();
	void ChangeState(GameState newState);
	GameState getState() const;

	//Menus
	//Main Menu
	void updateMainMenu();
	void updatePause();
	void updateCharacterSelection();
	
	/*Gameplay*/
	//Exploration
	void updateExploration();

	//Combat
	void updateCombat();


};