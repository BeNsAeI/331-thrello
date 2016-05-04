/*
 * MinimaxPlayer.h
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */

#ifndef MINIMAXPLAYER_H
#define MINIMAXPLAYER_H

#include "OthelloBoard.h"
#include "Player.h"
#include "Tree.h"
#include <vector>

/**
 * This class represents an AI player that uses the Minimax algorithm to play the game
 * intelligently.
 */
class MinimaxPlayer : public Player {
public:

	/**
	 * @param symb This is the symbol for the minimax player's pieces
	 */
	MinimaxPlayer(char symb);

	/**
	 * Destructor
	 */
	virtual ~MinimaxPlayer();

	/**
	 * @param b The board object for the current state of the board
	 * @param col Holds the return value for the column of the move
	 * @param row Holds the return value for the row of the move
	 */
    void get_move(OthelloBoard* b, int& col, int& row);
	int UtilityFunction(OthelloBoard* b, struct Tree* current, int depth, int sym, int outsym,int i); //Utility Function
	void _minimax(struct Tree * current, int i);							//MINIMAX FUNCTION
	void logic(OthelloBoard* b, struct Tree* current, int depth, int sym); //Successor function
	void nextMove(OthelloBoard* b);											//Supplies the next move from Logic tree
    /**
     * @return A copy of the MinimaxPlayer object
     * This is a virtual copy constructor
     */
    MinimaxPlayer* clone();

private:
	int cDepth;
	char symbol;
	char Osymbol;
	bool lastMap[4][4];
	BuildTree * myTree;
	struct Tree root;
	struct Tree * nm;
	bool rootIsSet;
};


#endif
