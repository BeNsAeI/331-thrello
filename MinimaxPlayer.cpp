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
	cDepth = 0;
}

MinimaxPlayer::~MinimaxPlayer() {
	delete myTree;
}

void MinimaxPlayer::logic(OthelloBoard* b, struct Tree* current, int depth,int sym)
{
	int pause;
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
			int outsym;
			if (sym == 'X')
				outsym = 'O';
			else
				outsym = 'X';
			current->branch[i].board = new OthelloBoard(*b);
			current->branch[i].move = validMoves[i];
			current->branch[i].depth = depth + 1;
			current->branch[i].leaf = true;
			current->branch[i].parent = current;
			current->branch[i].branch = NULL;
			current->branch[i].turn = sym;
			current->branch[i].value = 1 + myTree->moves[current->branch[i].move].value - myTree->moves[current->branch[i].move].risk + (current->branch[i].board->count_score(sym) - current->branch[i].board->count_score(outsym));
			struct Tree * it = current;
			while (it != &root)
			{
				it->value = it->value + current->branch[i].value;
				it = it->parent;
			}

			current->branch[i].board->play_move(myTree->moves[current->branch[i].move].pos[x], myTree->moves[current->branch[i].move].pos[y], sym);
//			current->branch[i].board->display();

			if (current->branch[i].board->count_score(sym) > current->branch[i].board->count_score(outsym))
				current->branch[i].value = current->branch[i].value + 2;
//						std::cout << "Value: " << current->branch[i].value  << std::endl;
//						std::cin >> pause;

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
bool match(OthelloBoard * a, OthelloBoard * b)
{
	if (a->get_cell(0, 0) == b->get_cell(0, 0) &&
		a->get_cell(0, 1) == b->get_cell(0, 1) &&
		a->get_cell(0, 2) == b->get_cell(0, 2) &&
		a->get_cell(0, 3) == b->get_cell(0, 3) &&

		a->get_cell(1, 0) == b->get_cell(1, 0) &&
		a->get_cell(1, 1) == b->get_cell(1, 1) &&
		a->get_cell(1, 2) == b->get_cell(1, 2) &&
		a->get_cell(1, 3) == b->get_cell(1, 3) &&

		a->get_cell(2, 0) == b->get_cell(2, 0) &&
		a->get_cell(2, 1) == b->get_cell(2, 1) &&
		a->get_cell(2, 2) == b->get_cell(2, 2) &&
		a->get_cell(2, 3) == b->get_cell(2, 3) &&

		a->get_cell(3, 0) == b->get_cell(3, 0) &&
		a->get_cell(3, 1) == b->get_cell(3, 1) &&
		a->get_cell(3, 2) == b->get_cell(3, 2) &&
		a->get_cell(3, 3) == b->get_cell(3, 3))
	{
		return true;
	}
	return false;
}
void MinimaxPlayer::nextMove(OthelloBoard* b)
{
	int tmpVal = 0;
	int tmpIndex = 0;
	struct Tree * tmp;
	if (!match(b,nm->board))
	{
		for (int i = 0; i < nm->count; i++)
		{
			if (match(b, nm->branch[i].board))
				nm = &nm->branch[i];
		}
	}
	tmpVal = 0;
	tmpIndex = 0;

	for (int i = 0; i < nm->count; i++)
	{
		tmp = &nm->branch[i];
		if (b->is_legal_move(myTree->moves[tmp->move].pos[x], myTree->moves[tmp->move].pos[y], symbol))
		{
			if (tmp->value > tmpVal)
			{
				tmpVal = tmp->value;
				tmpIndex = i;
			}
		}
	}
	if (DEBUG)
		std::cout << "** Value: " << tmpVal << std::endl;
	nm = &nm->branch[tmpIndex];
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
		if (!rootIsSet)
		{
			OthelloBoard * myboard = new OthelloBoard(*b);
			logic(myboard, &root, 0,symbol);
			if (DEBUG)
				std::cout << "Tree calculated." <<std::endl;
			nm = &root;
			nm->board = new OthelloBoard(*b);
		}
		nextMove(b);
		col = myTree->moves[nm->move].pos[x];
		row = myTree->moves[nm->move].pos[y];
	}
	cDepth++;
	if (DEBUG)
		std::cout << "MiniMaxBot selected " << col << " as colomn and " << row << " as row." << std::endl;

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
