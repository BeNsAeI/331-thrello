#ifndef TREE_H
#define TREE_H
#define x 0
#define y 1

#include "OthelloBoard.h"

class Node{
public:
	int pos[2];
	int value;
	int risk;
	bool valid;
};

struct Tree{
	int move;
	bool leaf;
	int value;
	struct Tree * branch;
	struct Tree * parent;
	int count;
	int depth;
	OthelloBoard* board;
	char turn;
};

class BuildTree{
public:
	BuildTree();
	BuildTree(int row, int col);
	~BuildTree();
	void moveGen(int row, int col);
	int value(int row, int col);
	int risk(int row, int col);
	bool isValid(int index, OthelloBoard* board,char symbol);
	Node * moves;
private:
	int riskMap[4][4];
	int valueMap[4][4];
};

#endif
