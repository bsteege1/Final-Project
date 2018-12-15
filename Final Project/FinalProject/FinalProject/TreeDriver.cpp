#include "randomString.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct TreeNode
{
	string ID = "";
	string parentID = "";
	string rawEvent = "";
	string leftHash = "";
	string rightHash = "";
	string lHist[20];
	string rHist[20];
	
	//hash funtion creates a hash for the IDs of the node
	string hashed(string one, string two)
	{
		hash<string> hasher;
		string characters = "";
		characters += one[0];
		characters += one[1];
		characters += one[2];
		characters += one[3];
		characters += two[0];
		characters += two[1];
		characters += two[2];
		characters += two[3];
		string hashedString = "";
		auto hashed = hasher(characters);
		hashedString = to_string(hashed);
		return hashedString;
	}

	//creates a random string for parent ID
	string genRand()
	{
		string output = "";
		srand(time(0));
		for (int z = 0; z < 1024; z++)
		{
			output += genRandom();
		}
		return output;
	}

	//Insert will create the initial node as a root if location = 0, otherwise it fills ID, Parent ID, and Raw Event as it is a child. 
	//
	TreeNode insert(string raw, string parID, int location)
	{
		TreeNode node;
		if (location > 0)
		{
			node.ID = hashed(raw, parID).substr(0, 8);
			node.parentID = parID;
			node.rawEvent = raw;
			hash<string> hasher1;
			auto leftHashed = hasher1((node.ID) + (node.parentID) + (node.rawEvent) + (node.leftHash) + (node.rightHash));
			node.leftHash = to_string(leftHashed).substr(0, 8);
			hash<string> hasher;
			auto rightHashed = hasher((node.ID) + (node.parentID) + (node.rawEvent) + (node.leftHash) + (node.rightHash));
			node.rightHash = to_string(rightHashed).substr(0, 8);
			return node;
		}
		else
		{
			node.parentID = genRand().substr(0,8);
			node.rawEvent = raw;
			node.ID = hashed(node.parentID, node.rawEvent).substr(0,8);
			return node;
		}
	}
	
	string updateLeft(TreeNode tree[], int k)
	{
		//if (!(k % 2))
		//{
			return tree[k].leftHash;
		//}
		//else
		//{
		//	return tree[k].rightHash;
		//}
		

	}

	string updateRight(TreeNode tree[], int k)
	{
		return tree[k].rightHash;
	}

	void updateTree(TreeNode testNode, TreeNode Tree[], int levels, int p, int j)
	{
		while (j > 0)
		{
			p = (j - 1) / 2;
			//determines whether to insert left or right
			if (j % 2) //right
			{
				hash<string> hasher;
				auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));
				Tree[p].rightHash = to_string(hashed).substr(0, 8);
				int xR(-1);
				for (int i = levels; i > xR; i--)
				{
					Tree[p].rHist[i] = testNode.updateRight(Tree, j);
				}

			}
			else //left
			{
				hash<string> hasher;
				auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));
				Tree[p].leftHash = to_string(hashed).substr(0, 8);
				int xL(-1);
				for (int i = levels; i > xL; i--)
				{
					Tree[p].lHist[i] = testNode.updateLeft(Tree, j);
				}
			}
			j = p;

		}
	}

	void displayTree(TreeNode Tree[], int size)
	{

		for (int i(0); i < size; i++)
		{
			cout << "NODE " << i << ": " << Tree[i].ID << endl;
		}
	}

	void displayNode(TreeNode tree[], string id, int size)
	{
		int i(0);
		
			//if (tree[i].ID == id)
			//{
				cout << "NODE ID:\t" << tree[i].ID << endl
					<< "PARENT ID:\t" << tree[i].parentID << endl
					<< "EVENT:\t" << tree[i].rawEvent << endl
					<< "LHASH:\t" << tree[i].leftHash << endl
					<< "RHASH:\t" << tree[i].rightHash << endl
					<< "LHIST:\t" << tree[i].lHist[0] << "\t" << tree[i].lHist[1] << "\t" << tree[i].lHist[2] << "\t" << tree[i].lHist[3] << endl
					<< "RHIST:\t" << tree[i].rHist[0] << "\t" << tree[i].rHist[1] << "\t" << tree[i].rHist[2] << "\t" << tree[i].rHist[3] << endl;
			//}
			//i++;
	
	}

	void updateContents(TreeNode tree[], string raw)
	{
		
	}
};

int main()
{
	//
	TreeNode Node;
	TreeNode Tree[15];
	int i(0);
	int p(0);
	int j(0);
	int levels(0);
	int treeSize = size(Tree);
	string e;

	
	
	//creates a full and complete binary tree set to a pre-defined length that is set in the TreeNode array
	while (i <= 14)
	{
		//sets j to the current location in the tree
		j = i;
		
		//The if statements determine the number of levels in the tree
		if (j == 0)
		{
			levels = 4;
		}
		else if (j == 1 || j == 2)
		{
			levels = 3;
		}
		else if (j > 2 && j < 7)
		{
			levels = 2;
		}
		else if (j > 7 && j < 15)
		{
			levels = 1;
		}
		cout << "enter e" << endl;
		cin >> e;
		//Calls insert function a total of i times to fill the tree
		Tree[i] = Node.insert(e, Tree[(i - 1)/2].ID, i);
		//Updates the tree everytime a new node is added by percolating up 
		Node.updateTree(Node, Tree, levels, p, j);
	
		i++;
	}

	Node.displayTree(Tree, treeSize);
	string input;
	cout << "INPUT ID" << endl;
	cin >> input;
	Node.displayNode(Tree, input, treeSize);
	//cout << Tree[0].ID << endl;
	//cout << Tree[1].ID << endl;
	//cout << Tree[2].ID << endl;
	//cout << Tree[3].ID << endl;
	//cout << Tree[4].ID << endl;
	//cout << Tree[5].ID << endl;
	//cout << Tree[6].ID << endl;
	//cout << Tree[14].leftHash << endl;
	//cout << Tree[14].rightHash << endl;
	//cout << Tree[6].lHist[0] << endl;
	//cout << Tree[2].lHist[1] << endl;
	//cout << Tree[0].rHist[2] << endl;
	//cout << Tree[0].lHist[3] << endl;
	system("pause");
	return 0;
}


/*
while (j > 0)
{
	p = (j - 1) / 2;
	//determines whether to insert left or right
	if (j % 2) //right
	{
		hash<string> hasher;
		auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));
		Tree[p].rightHash = to_string(hashed).substr(0, 8);
		int xR(0);
		for (int i = levels; i > xR; i--)
		{
			Tree[p].rHist[i] = testNode.updateRight(Tree, j);
		}

	}
	else //left
	{
		hash<string> hasher;
		auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));
		Tree[p].leftHash = to_string(hashed).substr(0, 8);
		int xL(-1);
		for (int i = levels; i > xL; i--)
		{
			Tree[p].lHist[i] = testNode.updateLeft(Tree, j);
		}
	}
	j = p;

}
*/