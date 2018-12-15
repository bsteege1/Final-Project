#include "randomString.h"

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
	string lHist[15];
	string rHist[15];
	
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
		string output;
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
			return node;
		}
		else
		{
			node.parentID = genRand();
			node.rawEvent = raw;
			node.ID = hashed(node.parentID, node.rawEvent).substr(0,8);
			return node;
		}
	}
	
	string update(TreeNode tree[], int k)
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
};



int main()
{
	

	TreeNode Tree[31];
	int i(0);
	int p(0);
	int j(0);
	int xL(0);
	int xR(0);


	TreeNode testNode;
	Tree[0] = testNode.insert("sfsdfgdfgdfgdf", "dgksdfsdfsdfsdfjhkjf", i);
	i++;
	while (i <= 30)
	{
		j = i;
		Tree[i] = testNode.insert("sfsdfgdfgdfgdf", Tree[(i - 1)/2].ID, i);
		
		while (j > 0)
		{
			p = (j - 1) / 2;
			//determines whether to insert left or right
			if (j % 2) //right
			{
				hash<string> hasher;
				auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));
				Tree[p].rightHash = to_string(hashed).substr(0, 8);
				
				Tree[p].rHist[xR] = "sdfsdfsdf";//testNode.update(Tree, j);
				
				xR++;
				
			}
			else //left
			{
				hash<string> hasher;
				auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));
				Tree[p].leftHash = to_string(hashed).substr(0, 8);
				Tree[p].lHist[xL] = "kl;kl;k;lk";//testNode.update(Tree, j);
				xL++;
			}
			j = p;
			//update(p, j);
			
		}
		i++;
	}
	cout << Tree[0].ID << endl;
	cout << Tree[1].ID << endl;
	cout << Tree[2].ID << endl;
	cout << Tree[14].lHist[0] << endl;
	system("pause");
	return 0;
}


