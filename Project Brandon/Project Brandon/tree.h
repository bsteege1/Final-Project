#ifndef TREE_H
#define TREE_H

#include "NodeData.h"


struct bst
{
	nodeData data;
	int leftIdx;
	int rightIdx;
};

void MakeNode(vector <struct bst> &v1, nodeData aData)
{
	struct bst b1 = { aData, -1, -1 };
	v1.push_back(b1);
}

void setleft(vector <struct bst>&v1, int currIndex, nodeData aData)
{
	unsigned int leftIndex = v1.size();
	v1[currIndex].leftIdx = leftIndex;
	struct bst b1 = { aData, -1, -1 };
	v1.push_back(b1);
}

void setright(vector<struct bst> &v1, int currIndex, nodeData aData)
{
	unsigned int rightIndex = v1.size();
	v1[currIndex].rightIdx = rightIndex;
	struct bst b1 = { aData, -1, -1 };
	v1.push_back(b1);
}

void Insert(vector<struct bst> &v1, nodeData aData)
{
	if (v1.size() == 0)
	{
		cout << "Note is not made yet. MakeNode first..." << endl;
		return;
	}
	unsigned int currentIdx = 0;
	while (currentIdx < v1.size())
	{
			if (v1[currentIdx].leftIdx == -1)
			{
				setleft(v1, currentIdx, aData);
				break;
			}
			else
				currentIdx = v1[currentIdx].leftIdx;
		
		
			if (v1[currentIdx].rightIdx == -1)
			{
				setright(v1, currentIdx, aData);
				break;
			}
			else
				currentIdx = v1[currentIdx].rightIdx;
		
	}
}

#endif

/*
class tree
{
	nodeData node;
	int leftIdx;
	int rightIdx;

public:
	void createNode(vector<class>, nodeData node);
};

void tree::createNode(vector<class> &tr, nodeData node)
{
	tree t1 = { node, -1, -1 };
	v1.push_back(b1);
}

*/