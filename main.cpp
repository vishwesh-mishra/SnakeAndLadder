#include "Services/Game.h"

int main() {
	Game* newGame = new Game();
	
	newGame->readInput();

	FILE* f;

	freopen_s(&f, "InputOutput/Output.txt", "w", stdout);
	string winner = newGame->runGame();
	newGame->printOutput(winner, 0, 0, 0);

	fclose(stdout);
}