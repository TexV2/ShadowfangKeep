#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
	cout << "Welcome to Shadowfang Keep!" << endl;
	try {
		Game game;
		game.Start();
		while (game.getState() != GameState::GAME_OVER)
		{
			game.Update();
		}
		game.Shutdown();
	}
	catch (const std::exception& e)
	{
		cerr << "An error occurred: " << e.what() << endl;
		return 1;
	}
	return 0;
}