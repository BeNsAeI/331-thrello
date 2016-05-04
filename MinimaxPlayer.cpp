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
	root.leaf = true;
	root.branch = NULL;
	root.count = 0;
	root.depth = 0;
	root.value = 0;
	root.move = 16;
	root.parent = NULL;

	if (symb == 'X')
		Osymbol = 'O';
	else
		Osymbol = 'X';
}

MinimaxPlayer::~MinimaxPlayer() {
	delete myTree;
}

void MinimaxPlayer::logic(OthelloBoard* b, struct Tree* current, int depth,int sym)
{
	rootIsSet = true;
	int validMoves[16];
	int counter = 0;
	for (int i = 0; i < 16; i++)
	{
		myTree->moves[i].valid = myTree->isValid(i, b, sym);
		if (myTree->moves[i].valid)
		{
			validMoves[counter] = i;
			counter++;
		}
	}
	if (counter != 0)
	{
		current->leaf = false;
		current->branch = new struct Tree[counter];
		current->count = counter;
		for (int i = 0; i < counter; i++)
		{
			current->branch[i].move = validMoves[i];
			current->branch[i].depth = depth + 1;
			current->branch[i].leaf = true;
			current->branch[i].parent = current;
			current->branch[i].branch = NULL;
			current->branch[i].value = myTree->moves[current->branch[i].move].value - myTree->moves[current->branch[i].move].risk;
			current->branch[i].board = new OthelloBoard(*b);
			current->branch[i].board->play_move(myTree->moves[current->branch[i].move].pos[x], myTree->moves[current->branch[i].move].pos[y], sym);
			int outsym;
			if (sym == 'X')
				outsym = 'O';
			else
				outsym = 'X';
			if (current->branch[i].board->count_score(sym) > current->branch[i].board->count_score(outsym))
				current->branch[i].value = current->branch[i].value + 2;
			logic(current->branch[i].board, &current->branch[i], depth + 1, outsym);
		}
		
	}
	else
	{
		current->leaf = true;
		current->branch = NULL;
		current->count = 0;
		
		current->value = 0;
	}
	

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
	}
	if (AI)
	{
		if (!rootIsSet)
		{
			OthelloBoard * myboard = new OthelloBoard(*b);
			logic(myboard, &root, 0,symbol);
		}
		std::cout << "Tree calculated." <<std::endl;
	}
	col = myTree->moves[index].pos[x];
	row = myTree->moves[index].pos[y];
	std::cout << "MiniMaxBot selected " << col << " as colomn and " << row << " as row." << std::endl;

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
