/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"
#include "Tree.h"

using std::vector;

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {
	myTree = new BuildTree();
	symbol = symb;
}

MinimaxPlayer::~MinimaxPlayer() {
	delete myTree;
}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
	int i = 0;
	myTree->moves[i].valid = myTree->isValid(i, b, symbol);
	while (!myTree->moves[i].valid )
	{
		i++;
		myTree->moves[i].valid = myTree->isValid(i,b,symbol);
	}
	col = myTree->moves[i].pos[x];
	row = myTree->moves[i].pos[y];
	std::cout << "MiniMaxBot selected " << col << " as colomn and " << row << " as row." << std::endl;

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
