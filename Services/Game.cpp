#include<iostream>
#include<random>
#include "Game.h"

Game::Game() {
	this->snakeLadder.clear();
	this->playerPosition.clear();
}

void Game::readInput() {
	FILE* f;

	freopen_s(&f, "InputOutput/Input.txt", "r", stdin);

	int i, snakes, ladders, headStart, tailEnd, players;
	string playerName, winner;

	cin >> snakes;
	for (i = 0;i < snakes;i++) {
		cin >> headStart >> tailEnd;
		this->addSnakeLadder(headStart, tailEnd);
	}

	cin >> ladders;
	for (i = 0;i < ladders; i++) {
		cin >> headStart >> tailEnd;
		this->addSnakeLadder(headStart, tailEnd);
	}

	cin >> players;
	for (i = 0;i < players;i++) {
		cin >> playerName;
		this->addPlayer(playerName);
	}
}

void Game::printOutput(string player, int diceRoll = 0, int startPosition = 0, int endPosition = 0) {
	if (diceRoll == 0) cout << player << " wins the game" << endl;
	else cout << player << " rolled a " << diceRoll << " and moved from " << startPosition << " to " << endPosition << endl;
}

void Game::addSnakeLadder(int headStart, int tailEnd) {
	snakeLadder[headStart] = tailEnd;
}

void Game::addPlayer(string name) {
	playerPosition[name] = 0;
}

int Game::rollDice() {
	int diceRoll = rand() % 6 + 1;
	return diceRoll;
}

string Game::runGame() {
	map<string, int>::iterator it;
	string currentPlayer;
	int diceRoll, startPosition = 0, prevPosition, endPosition = 0;

	it = playerPosition.begin();
	while (it != playerPosition.end() && endPosition != 100) {
		currentPlayer = it->first;
		startPosition = it->second;
		diceRoll = rollDice();
		playerPosition[currentPlayer] += diceRoll;
		if(playerPosition[currentPlayer] > 100) playerPosition[currentPlayer] -= diceRoll;

		while (snakeLadder.find(playerPosition[currentPlayer]) != snakeLadder.end()) 
			playerPosition[currentPlayer] = snakeLadder[playerPosition[currentPlayer]];
		
		endPosition = playerPosition[currentPlayer];
		printOutput(currentPlayer, diceRoll, startPosition, endPosition);
		it++;
		if (it == playerPosition.end() && endPosition < 100) it = playerPosition.begin();
	}

	return currentPlayer;
}