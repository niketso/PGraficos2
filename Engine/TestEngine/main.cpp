#include "Game.h"

int main() {

	GameBase* game = new Game();

	//TODO: startup
	if (game->Start()) {
		game->Loop();
	}

	game->Stop();

	delete game;
	std::cin.get();
	return 0;
}