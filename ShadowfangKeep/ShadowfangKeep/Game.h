#pragma once
enum class GameState
{
	MAIN_MENU,
	CHARACTERSELECTION,
	EXPLORATION,
	PAUSED,
	GAME_OVER
};

class Game
{
private:
	GameState currentState;
public:
	/*Management*/
	Game();
	~Game();
	void Start();
	void Update();
	void Shutdown();
	void ChangeState(GameState newState);
	GameState getState();

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