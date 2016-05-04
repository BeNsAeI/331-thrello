#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "GameDriver.h"

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "Usage: othello <player1 type> <player2 type>" << std::endl;
		exit(-1);
	}
	GameDriver* game = new GameDriver(argv[1], argv[2], 4, 4);
	game->run();
	return 0;
}