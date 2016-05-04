#include <iostream>
#include "Const.h"
#include "Tree.h"

BuildTree::BuildTree()
{
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
	moves = new Tree[16];
	moveGen(4, 4);
}

BuildTree::BuildTree(int row, int col)
{
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
	valueMap[0][1] = 2;
	valueMap[0][2] = 2;
	valueMap[1][0] = 2;
	valueMap[2][0] = 2;
	valueMap[3][1] = 2;
	valueMap[3][2] = 2;
	valueMap[1][3] = 2;
	valueMap[2][3] = 2;
	valueMap[1][1] = 5;
	valueMap[2][2] = 5;
	valueMap[1][2] = 5;
	valueMap[2][1] = 5;

	int p = row * col;
	moves = new Tree[p];
	moveGen(row,col);
}

BuildTree::~BuildTree()
{
	delete moves;
}
int  BuildTree::value(int row, int col)
{
	return valueMap[row][col];
}
int  BuildTree::risk(int row, int col)
{
	return riskMap[row][col];
}
bool BuildTree::isValid(int index, OthelloBoard* board, char symbol)
{
	return board->is_legal_move(moves[index].pos[x], moves[index].pos[y], symbol);
}

void BuildTree::moveGen(int row, int col)
{
	int xv = 0;
	int yv = 0;;
	for (int i = 0; i < row * col; i++)
	{
		if (xv < 4)
		{
			moves[i].pos[x] = xv;
			moves[i].pos[y] = yv;
			xv++;
		}
		else
		{
			xv = 0;
			yv++;
			moves[i].pos[x] = xv;
			moves[i].pos[y] = yv;
			xv++;
		}
		moves[i].valid = false;
		moves[i].value = value(moves[i].pos[y], moves[i].pos[x]);
		moves[i].risk = risk(moves[i].pos[y], moves[i].pos[x]);
		if (DEBUG)
		{
			std::cout << "Moves[" << i << "].pos[x] = " << moves[i].pos[x] << std::endl;
			std::cout << "Moves[" << i << "].pos[y] = " << moves[i].pos[y] << std::endl;
		}
	}
}