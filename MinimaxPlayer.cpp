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
	riskMap[0][0] = 0;
	riskMap[3][0] = 0;
	riskMap[0][3] = 0;
	riskMap[3][3] = 0;
	riskMap[0][1] = 1;
	riskMap[0][2] = 1;
	riskMap[1][0] = 1;
	riskMap[2][0] = 1;
	riskMap[3][1] = 1;
	riskMap[3][2] = 1;
	riskMap[1][3] = 1;
	riskMap[2][3] = 1;
	riskMap[1][1] = 3;
	riskMap[2][2] = 3;
	riskMap[1][2] = 3;
	riskMap[2][1] = 3;

	valueMap[0][0] = 5;
	valueMap[3][0] = 5;
	valueMap[0][3] = 5;
	valueMap[3][3] = 5;
	valueMap[0][1] = 3;
	valueMap[0][2] = 3;
	valueMap[1][0] = 3;
	valueMap[2][0] = 3;
	valueMap[3][1] = 3;
	valueMap[3][2] = 3;
	valueMap[1][3] = 3;
	valueMap[2][3] = 3;
	valueMap[1][1] = 5;
	valueMap[2][2] = 5;
	valueMap[1][2] = 5;
	valueMap[2][1] = 5;

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {


	std::cout << "MiniMaxBot selected " << col << " as colomn and " << row << " as row." << std::endl;


}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
