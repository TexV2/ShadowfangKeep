#include "game.h"
#include "MainMenu.h"
#include <iostream>

/*Game Management*/
Game::Game() : currentState(GameState::MAIN_MENU)
{

}
Game::~Game()
{
}
void Game::Start()
{
    currentState = GameState::MAIN_MENU;
}
void Game::Update()
{
   
    switch (currentState)
    {
    case GameState::MAIN_MENU:
        updateMainMenu();
        break;
	case GameState::CHARACTERSELECTION:
        //updateCharacterSelection();
		break;

    case GameState::EXPLORATION:
        updateExploration();
        break;

    case GameState::PAUSED:
        updatePause();
        break;

    case GameState::GAME_OVER:
        // do nothing, main loop will exit
        break;
    }
}
void Game::Shutdown()
{

}
void Game::ChangeState(GameState newState)
{
	currentState = newState;
	std::cout << "Game state changed." << std::endl;
}

GameState Game::getState()
{
	return currentState;
}

/*Menus*/
void Game::updateMainMenu()
{
    auto mainMenu = std::make_unique<MainMenu>();
    mainMenu->displayOptions();
    MenuAction action = mainMenu->getUserChoice();
    if (MenuAction::START_NEW_GAME == action)
    {
        ChangeState(GameState::CHARACTERSELECTION);
    }
    else if (MenuAction::EXIT_GAME == action)
    {
        ChangeState(GameState::GAME_OVER);
	}
}


void Game::updateCharacterSelection()
{

}

/*Gameplay*/
void Game::updateExploration()
{
}

void Game::updateCombat()
{
}