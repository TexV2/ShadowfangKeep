#include "game.h"
#include "Player.h"
#include "MainMenu.h"
#include "CharacterMenu.h"
#include "Warrior.h"
#include "ExplorationMenu.h"
#include <memory>
#include <iostream>
#include "EnemyRoom.h"
#include "LootRoom.h"
#include <limits>

/*Game Management*/
Game::Game() : currentState(GameState::MAIN_MENU)
{
	worldBuilder = Worldbuilder();
	rooms = worldBuilder.buildWorld();
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

int Game::getIndex() const
{
	return this->currentRoomIndex;
}

void Game::setIndex(int index)
{
	this->currentRoomIndex = index;
}

bool Game::getIsRoomEmpty() const
{
    return this->rooms[currentRoomIndex]->getIsRoomEmpty();
}

void Game::setIsRoomEmpty(bool isEmpty)
{
    this->rooms[currentRoomIndex]->setIsRoomEmpty(isEmpty);
}

void Game::makePlayer(std::string name, int playerClass)
{
    if (playerClass == 1) // Warrior
    {
        player = std::make_unique<Warrior>(name);
	}
}

void Game::saveGame()
{ 
    try
    {
        saveSystem = std::make_unique<SaveSystem>(currentRoomIndex, rooms[currentRoomIndex]->getIsRoomEmpty(), player.get());
        saveSystem->saveGame();
		std::cout << "Game has been saved!" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
	}
}
void Game::loadGame()
{
    try
    {
        saveSystem = std::make_unique<SaveSystem>();
        Loading data = saveSystem->loadGame();
        makePlayer(data.playerName, data.playerClass);
        currentRoomIndex = data.roomIndex;
        this->rooms[currentRoomIndex]->setIsRoomEmpty(data.isRoomEmpty);
		std::cout << "Game has been loaded!" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
	}
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
			loadGame();
            ChangeState(GameState::EXPLORATION);
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
	CharacterMenu charMenu;
	charMenu.displayOptions();
	MenuAction action = charMenu.getUserChoice();
    std::string name;
    std::cout << "Choose a name for your character: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    switch (action) {
    case MenuAction::WARRIOR:
		makePlayer(name, 1);
        break;
    }
	  std::cout << "Character Created!" << std::endl;
	  std::cout << player->toString() << std::endl;
	  currentState = GameState::EXPLORATION;
}

/*Gameplay*/
auto printRoomSummary = [&](Room& r)
    {
        std::cout << "There is " << (r.getIsRoomEmpty() ? "nothing" : "something") << " in the room\n";
    };
void Game::updateExploration()
{
    if (rooms[currentRoomIndex]->getVisited() == false)
    { 	
        rooms[currentRoomIndex]->enter(*player);
		rooms[currentRoomIndex]->setVisited(true);
        if (rooms[currentRoomIndex]->getIsRoomEmpty() == false)
        {
            if (rooms[currentRoomIndex]->getHasEnemy() == true)
            {
                ChangeState(GameState::COMBAT);
                return;
            }
		}
    }
    ExplorationMenu exploreMenu;
    exploreMenu.displayOptions();
	MenuAction action = exploreMenu.getUserChoice();
    switch (action) {
    case MenuAction::CONTINUE:
        if (currentRoomIndex + 1 >= rooms.size())
        {
            std::cout << "You have reached the end of the game. Congratulations!" << std::endl;
            ChangeState(GameState::GAME_OVER);
            return;
		}
        currentRoomIndex++;
        break;
    case MenuAction::SEARCH_ROOM:
        printRoomSummary(*rooms[currentRoomIndex]);
		searchRoom(rooms[currentRoomIndex].get());
        break;
    case MenuAction::OPEN_INVENTORY:
		openInventory();
        break;
    case MenuAction::SAVE_GAME:
        saveGame();
		break;
    case MenuAction::EXIT_GAME:
		ChangeState(GameState::GAME_OVER);
        break;
    }
}

void Game::searchRoom(Room* currentRoom)
{
    //if (auto lootRoom = dynamic_cast<LootRoom*>(rooms[currentRoomIndex].get()))
    if (auto lootRoom = dynamic_cast<LootRoom*>(currentRoom))
    {
        lootRoom->searchRoom(*player);
        currentRoom->setIsRoomEmpty(true);
    }
}

void Game::openInventory()
{
    while (true)
    {
        std::cout << player->toString() << std::endl;
        std::cout << "Inventory Items:\n"
            << player->getInventoryItems() << std::endl;

        std::cout << "Enter the name of the item to equip it, or type 'exit' to close the inventory: ";

        std::string itemName;
        std::getline(std::cin, itemName);

        if (itemName == "exit")
        {
            break;
        }

        player->equipItem(itemName, *player);
    }
}

void Game::updateCombat()
{
	currentEnemy = dynamic_cast<EnemyRoom*>(rooms[currentRoomIndex].get())->releaseEnemy();
	while (player->isAlive() && rooms[currentRoomIndex]->getHasEnemy() == true)
    {
        std::cout << "1. Attack \n2. Defend\n";
		int choice;
		std::cin >> choice;
        if (choice == 1)
        {
            int damageDealt = player->dealDamage(*currentEnemy);
			std::cout << "You attack " << currentEnemy->getName() << " for " << damageDealt << " damage!\n";
        }
        if (currentEnemy->isAlive())
        {
            currentEnemy->takeTurn(*player);
        }
        else
        {
            std::cout << "You have defeated the " << currentEnemy->getName() << "!\n";
			std::cout << rooms[currentRoomIndex]->getExit() << std::endl;
            rooms[currentRoomIndex]->setHasEnemy(false);
            rooms[currentRoomIndex]->setIsRoomEmpty(true);
            currentEnemy.reset();
            ChangeState(GameState::EXPLORATION);
		}
	}
}