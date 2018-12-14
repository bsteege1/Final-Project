
#ifndef _TREE_H_
#define _TREE_H_
#include "NodeData.h"
#include <iostream>

using namespace std;

class Tree
{
public:
	nodeData data;
	Tree* Right;
	Tree* Left;
	Tree* Parent;
	Tree findEmpty(Tree* node);
};

Tree* Current = NULL;
Tree* placeHolder = NULL;

//Borrowed From Lab 8
int height(const Tree * subtree)
{
	if (subtree == NULL) //checks to see if tree is empty
	{
		return 0;
	}
	else if (height(subtree->Right) > height(subtree->Left)) //if the height of the right subtree is greater than the left
	{
		return 1 + height(subtree->Right); //return 1 + the height of the right subtree
	}
	else
	{
		return 1 + height(subtree->Left); //return 1 + the height of the left subtree
	}
}

void fillLeft(Tree* node)
{
	//Current = node;
	//node->Left = Current;
	if (node->Left == NULL)
	{
		node->Left = new Tree;
		Tree* LeftBranch = NULL;
		LeftBranch = new Tree;
		//initializeRoot(LeftBranch);
		node->Left = LeftBranch;
		//cout << "passed left" << endl;
	}
}

void fillRight(Tree* node)
{
	Current = node;
	node->Parent = Current;
	if (!(node->Right))
	{
		node->Right = new Tree;
		Tree* RightBranch = NULL;
		RightBranch = new Tree;
		node->Right = RightBranch;
	}
}

//fills an entire row of the binary tree
//sets current to the node the function is called on to allow for the setting of the parent node
//then sets current to the left node of the tree and determines if it is empty and needs to be filled
//This process is repeated with the right node. 
int fillRow(Tree* node, int c)
{
	Current = node;
	//placeHolder = node->Left->Parent;
	//Current = node->Left;
	if ((node->Left == NULL) && (node->Right == NULL))
	{
		cout << "sdfskldjfklsdjf" << endl;
		fillLeft(Current);
		fillRight(Current);
		c++; //lol
	}
	else
	{
		cout << "This row is full" << endl;
	}
	return c;
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
	if (node)
	{
		cout << node->data.printNode() << endl;
		Print(node->Left);
		Print(node->Right);
	}
}




#endif

