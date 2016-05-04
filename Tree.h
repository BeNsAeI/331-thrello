#ifndef TREE_H
#define TREE_H
#define x 0
#define y 1

class Tree{
public:
	int pos[2];
	int value;
	int risk;
	bool valid;
};

class BuildTree{
public:
	BuildTree();
	BuildTree(int row, int col);
	~BuildTree();
	void moveGen(int row, int col);
	int value(int row, int col);
	int risk(int row, int col);
	bool isValid();
private:
	Tree * moves;
	int riskMap[4][4];
	int valueMap[4][4];
};

#endif