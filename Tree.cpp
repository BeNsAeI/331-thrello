#include <iostream>
#include "Tree.h"

BuildTree::BuildTree(){
	moves = new Tree[16];
}

BuildTree::BuildTree(int row, int col){

	int p = row * col;
	moves = new Tree[p];
}

BuildTree::~BuildTree()
{
	delete moves;
}

void BuildTree::moveGen(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{

		}
	}
}

bool BuildTree::isValid()
{
	if (0)
		return false;
	return true;
}