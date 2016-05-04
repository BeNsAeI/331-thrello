#include <iostream>
#include "Tree.h"

BuildTree::BuildTree(){
	head = new Tree;
	index = head;
}

BuildTree::BuildTree(int row, int col){
	head = new Tree;
	index = head;
}

BuildTree::~BuildTree()
{
	
}

bool BuildTree::isValid()
{
	return true;
}