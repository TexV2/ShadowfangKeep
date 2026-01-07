#pragma once
#include <memory>
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
	GameState currentState;
	std::unique_ptr<Player> player;
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