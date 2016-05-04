/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "Const.h"
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
	int index = 0;
	if (NOAI)
	{
		myTree->moves[index].valid = myTree->isValid(index, b, symbol);
		while (!myTree->moves[index].valid)
		{
			index++;
			myTree->moves[index].valid = myTree->isValid(index, b, symbol);
		}
	}
	col = myTree->moves[index].pos[x];
	row = myTree->moves[index].pos[y];
	std::cout << "MiniMaxBot selected " << col << " as colomn and " << row << " as row." << std::endl;

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
