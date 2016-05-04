#ifndef TREE_H
#define TREE_H

struct Tree{
	int value;
	int risk;
	bool valid;
	struct Tree * b;
};
class BuildTree{
public:
	BuildTree();
	BuildTree(int row, int col);
	~BuildTree();
	bool isValid();
	struct Tree * head;
	struct Tree * index;
};

#endif