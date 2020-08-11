#pragma once
#include<map>
#include<string>

using namespace std;

class Game {
public:
	map<string, int> playerPosition;
	map<int, int> snakeLadder;

	Game();
	void readInput();
	void printOutput(string player, int diceRoll, int startPosition, int endPosition);
	void addSnakeLadder(int headStart, int tailEnd);
	void addPlayer(string name); 
	int rollDice();
	string runGame();
};
