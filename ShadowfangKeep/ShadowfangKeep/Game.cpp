#include "game.h"
#include "MainMenu.h"
#include <memory>
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
		updateCharacterSelection();
		break;

    case GameState::EXPLORATION:
        updateExploration();
        break;

    case GameState::PAUSED:
        updatePause();
        break;

    case GameState::COMBAT:
        updateCombat();
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

GameState Game::getState() const
{
	return currentState;
}

/*Menus*/
void Game::updateMainMenu()
{
    MainMenu mainMenu;
    mainMenu.displayOptions();
    MenuAction action = mainMenu.getUserChoice();
    switch (action) {
        case MenuAction::START_NEW_GAME:
        ChangeState(GameState::CHARACTERSELECTION);
		break;
        case MenuAction::LOAD_GAME:
            // Implement load game logic here
            break;
        case MenuAction::OPTIONS:
            // Implement options logic here
            break;
        case MenuAction::EXIT_GAME:
            ChangeState(GameState::GAME_OVER);
            break;
        default:
			break;
    }
}

void Game::updatePause()
{

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