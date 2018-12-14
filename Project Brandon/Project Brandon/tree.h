
#ifndef _TREE_H_
#define _TREE_H_

#include "NodeData.h"
#include <iostream>

using namespace std;

struct Tree {
	nodeData data;
	Tree* Right;
	Tree* Left;
	Tree* Parent;
};

Tree* Current = NULL;

void initializeRoot(Tree* rt)
{
	nodeData node;
	rt->data = node;
	//rt->Left = NULL;
	//rt->Right = NULL;
	//rt->Parent = NULL;
}

void fillLeft(Tree* node)
{
	Current = node;
	node->Left = Current;
	if (node->Left == NULL)
	{
		Tree* LeftBranch = NULL;
		//initializeRoot(LeftBranch);
		node->Left = LeftBranch;
	}
}

void fillRight(Tree* node)
{
	Current = node;
	node->Parent = Current;
	if (!(node->Right))
	{
		Tree* RightBranch = NULL;
		node->Right = RightBranch;
	}
}

//fills an entire row of the binary tree
//sets current to the node the function is called on to allow for the setting of the parent node
//then sets current to the left node of the tree and determines if it is empty and needs to be filled
//This process is repeated with the right node. 
void fillRow(Tree* node, int c)
{
	Current = node;
	node->Parent = Current;
	Current = node->Left;
	if (Current == NULL)
	{
		fillLeft(Current);
		c++; //lol
	}
	else
	{
		cout << "This row is full" << endl;
	}

}

void cascadeUp(Tree* node, int c)
{
	while (c > 0)
	{
		Current = node->Parent;
		c--;
		cascadeUp(Current, c);
	}
}

void Print(Tree* node) {
	if (node) {
		Print(node->Left);
		cout << node->data.printNode() << endl;
		Print(node->Right);
	}
}

#endif

