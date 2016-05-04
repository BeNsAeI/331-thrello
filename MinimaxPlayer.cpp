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
	rootIsSet = false;
}

MinimaxPlayer::~MinimaxPlayer() {
	delete myTree;
}
int MinimaxPlayer::logic(OthelloBoard* b,int pos, int depth)
{
	int myMove[2];
	if (!rootIsSet)
	{
		int validMoves[16];
		int counter = 0;
		for (int i = 0; i < 16; i++)
		{
			myTree->moves[i].valid = myTree->isValid(i, b, symbol);
			if (myTree->moves[i].valid)
			{
				validMoves[counter] = i;
				counter++;
			}
		}
		if (counter != 0)
		{
			root.leaf = false;
			root.branch = new struct Tree[counter];
			root.parent = NULL;
			root.count = counter;
			root.depth = 0;
			
		}
		else
		{
			root.leaf = true;
			root.branch = NULL;
			root.parent = NULL;
			root.count = 0;
			root.depth = 0;
		}
		std::cout << counter << " Valid moves found" << std::endl;
		rootIsSet = true;
	}



	//myMove[x] = myTree->moves[index].pos[x];
	//myMove[y] = myTree->moves[index].pos[y];


	if (pos == x)
		return myMove[x];
	return myMove[y];
}
void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
	int index;
	if (NOAI)
	{
		index = 0;
		myTree->moves[index].valid = myTree->isValid(index, b, symbol);
		while (!myTree->moves[index].valid)
		{
			index++;
			myTree->moves[index].valid = myTree->isValid(index, b, symbol);
		}
		col = myTree->moves[index].pos[x];
		row = myTree->moves[index].pos[y];
	}
	if (AI)
	{
		col = logic(b,x, 0);
		row = logic(b,y, 0);
	}

	std::cout << "MiniMaxBot selected " << col << " as colomn and " << row << " as row." << std::endl;

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
