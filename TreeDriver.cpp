//Final-Project
//TreeDriver.cpp
//COSC 2030
//Brandon Steege and Leonardo Garcia
//12/15/18


#include "randomString.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct TreeNode
{
	//Declares node stucture parameters
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
	TreeNode insert(string raw, string parID, int location)
	{
		TreeNode node;
		if (location > 0)//fills nodes other than root
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
		else//Fills the root node
		{
			node.parentID = genRand().substr(0,8);
			node.rawEvent = raw;
			node.ID = hashed(node.parentID, node.rawEvent).substr(0,8);
			return node;
		}
	}
	
	//returns a string value found in the left hash of the current location to be used in parent left history
	string updateLeft(TreeNode tree[], int j)
	{
		return tree[j].leftHash;
	}
	//returns a string value found in the left hash of the current location to be used in parent right history
	string updateRight(TreeNode tree[], int j)
	{
		return tree[j].rightHash;
	}

	//updates the entire tree by percolating up until j is the root
	void updateTree(TreeNode testNode, TreeNode Tree[], int levels, int p, int j)
	{
		while (j > 0) //whileloop continues until j is the root
		{
			p = (j - 1) / 2; //sets parent node

			//determines whether to insert left or right
			if (!(j % 2)) //right
			{
				hash<string> hasher;
				auto hashed = hasher((Tree[j].ID) + (Tree[j].parentID) + (Tree[j].rawEvent) + (Tree[j].leftHash) + (Tree[j].rightHash));//creates a hash for the parent node using data from child
				Tree[p].rightHash = to_string(hashed).substr(0, 8);//sets the right hash to the new hash created above
				int xR(-1);
				for (int i = levels; i > xR; i--)//for loop used to fill the history of the parent
				{
					Tree[p].rHist[i] = testNode.updateRight(Tree, j); //sets the value at location i in history to j which is the current node
					//The j is the current value, if it is greater than 2, it still needs to move up to fill the rest of the current history, otherwise it needs to go to the node after root without going all the way to root 
					if (j > 2) 
					{
						j = j - 2;
					}
					else
					{
						j = 2;
					}
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
					if (j > 2)
					{
						j = j - 2;
					}
					else
					{
						j = 1;
					}
				}
			}
			j = p; //moves to parent node to cascade up

		}
	}

	//This function outpupts the id's of all nodes in the tree
	void displayTree(TreeNode Tree[], int size)
	{

		for (int i(0); i < size; i++)
		{
			if (i == 0)
			{
				cout << "NODE " << i << ": " << Tree[i].ID << endl;
			}
			else if (i > 0 && i < 3)
			{
				cout << "\tNODE " << i << ": " << Tree[i].ID << endl;
			}
			else if (i > 2 && i < 7)
			{
				cout << "\t\tNODE " << i << ": " << Tree[i].ID << endl;
			}
			else
			{
				cout << "\t\t\tNODE " << i << ": " << Tree[i].ID << endl;
			}
			
		}
	}
	//this function outputs all information in a node
	void displayNode(TreeNode tree[], string id, int size)
	{
		int i(0);
		i = size;
		
			if (tree[i].ID == id)
			{
				cout << "NODE ID:\t" << tree[i].ID << endl
					<< "PARENT ID:\t" << tree[i].parentID << endl
					<< "EVENT:    \t" << tree[i].rawEvent << endl
					<< "LHASH:    \t" << tree[i].leftHash << endl
					<< "RHASH:    \t" << tree[i].rightHash << endl
					<< "LHIST:    \t" << tree[i].lHist[0] << "\t" << tree[i].lHist[1] << "\t" << tree[i].lHist[2] << "\t" << tree[i].lHist[3] <<
					"\t" << tree[i].lHist[4] << "\t" << tree[i].lHist[5] << "\t" << tree[i].lHist[6] << "\t" << tree[i].lHist[7] << "\t" << tree[i].lHist[8] <<
					"\t" << tree[i].lHist[9] << "\t" << tree[i].lHist[10] << "\t" << tree[i].lHist[11] << "\t" << tree[i].lHist[12] << "\t" << tree[i].lHist[13] <<
					"\t" << tree[i].lHist[14] << "\t" << tree[i].lHist[15] << "\t" << tree[i].lHist[16] << "\t" << tree[i].lHist[17] << "\t" << tree[i].lHist[18] <<
					"\t" << tree[i].lHist[19] << endl
					<< "RHIST:    \t" << tree[i].rHist[0] << "\t" << tree[i].rHist[1] << "\t" << tree[i].rHist[2] << "\t" << tree[i].rHist[3] <<
					"\t" << tree[i].rHist[4] << "\t" << tree[i].rHist[5] << "\t" << tree[i].rHist[6] << "\t" << tree[i].rHist[7] << "\t" << tree[i].rHist[8] <<
					"\t" << tree[i].rHist[9] << "\t" << tree[i].rHist[10] << "\t" << tree[i].rHist[11] << "\t" << tree[i].rHist[12] << "\t" << tree[i].rHist[13] <<
					"\t" << tree[i].rHist[14] << "\t" << tree[i].rHist[15] << "\t" << tree[i].rHist[16] << "\t" << tree[i].rHist[17] << "\t" << tree[i].rHist[18] <<
					"\t" << tree[i].rHist[19] << endl;
			}
			else
			{
				i++;
				displayNode(tree, id, i);
			}
	
	}
	// updates histories when a raw event is changed by the user
	void updateNodeContents(TreeNode tree[], string raw, string id, int size)
	{
		//intitializing variables
		int i(0);
		int j(0);
		int p(0);
		i = size;
		j = i;

		//starts the update once the correct id is found
		if (tree[i].ID == id)
		{
			//changes the raw event
			tree[i].rawEvent = raw;
			//ensures that j is never the root
			while (j > 0)
			{
				//find parent value based on child
				p = (j - 1) / 2;
				//checks if j is right child
				if (!(i % 2))
				{
					//creates new right hash
					hash<string> hasher;
					auto rightHashed = hasher((tree[i].ID) + (tree[i].parentID) + (tree[i].rawEvent) + (tree[i].leftHash) + (tree[i].rightHash));
					tree[i].rightHash = to_string(rightHashed).substr(0, 8);
					int x(0);
					while (tree[p].rHist[x] != "")
					{
						x++;
					}
					tree[p].rHist[x] = tree[i].rightHash;
					

				}
				else//checks if j is left child
				{
					tree[i].rawEvent = raw;
					hash<string> hasher1;
					auto leftHashed = hasher1((tree[i].ID) + (tree[i].parentID) + (tree[i].rawEvent) + (tree[i].leftHash) + (tree[i].rightHash));
					tree[i].leftHash = to_string(leftHashed).substr(0, 8);
					int x(0);
					while (tree[p].lHist[x] != "")
					{
						x++;
					}
					tree[p].lHist[x] = tree[i].leftHash;
				}
				j = p;//sets j to parent
			}
		}
		else//if input != id, then i is incremented and the function is called again with new i value
		{
			i++;
			updateNodeContents(tree, raw, id, i);
		}
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

	
	cout << "Please enter 15 raw events that are less than 1024 characters in length one at a time" << endl;
	//creates a full and complete binary tree set to a pre-defined length that is set in the TreeNode array
	while (i <= 14)
	{
		//sets j to the current location in the tree
		j = i;
		
		//The if statements determine the number of levels in the tree
		if (j == 0)
		{
			levels = 3;
		}
		else if (j == 1 || j == 2)
		{
			levels = 2;
		}
		else if (j > 2 && j < 7)
		{
			levels = 1;
		}
		else
		{
			levels = 0;
		}
		
		cin >> e;
		if (e.length() < 4)
		{
			e += "abcde";
		}
		else if (e.length() > 1024)
		{
			e.substr(0, 1024);
		}
		cout << "Enter another Raw Event: " << endl;
		//Calls insert function a total of i times to fill the tree
		Tree[i] = Node.insert(e, Tree[(i - 1)/2].ID, i);
		//Updates the tree everytime a new node is added by percolating up 
		i++;
		Node.updateTree(Node, Tree, levels, p, j);
	}
	cout << "TEST: " << Tree[0].lHist[0];
////////////////////////////////////////////////////////////////////// USER INTERFACE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	string input = "";
	cout << "\n\nA tracking tree with 15 nodes containing your raw events has been created. Please enter these functions to modify the tree" << endl
		<< "	'DisplayTree',	'DisplayNode',	'UpdateNode',	or 'end' to exit the program." << endl;
	cin >> input;
	while (input != "end")
	{
		if (input == "DisplayTree")
		{
			cout << endl;
			Node.displayTree(Tree, treeSize);
			cout << endl << "Enter a new command: ";
			cin >> input;
		}
		else if (input == "DisplayNode")
		{
			string nodeID1;
			cout << endl << "Enter a valid node ID: " << endl;
			cin >> nodeID1;
			cout << endl;
			Node.displayNode(Tree, nodeID1, 0);
			cout << endl << "Enter a new command: ";
			cin >> input;
		}
		else if (input == "UpdateNode")
		{
			string nodeID2;
			cout << endl << "Enter a valid node ID: " << endl;
			cin >> nodeID2;
			cout << endl << endl << "Now enter a new raw event to update: " << endl;
			string newE;
			cin >> newE;
			Node.updateNodeContents(Tree, newE, nodeID2, 0);
			cout << endl << "Enter a new command: ";
			cin >> input;
		}
		else
		{
			cout << "You did not enter a valid command, please enter one of the commands shown below:" << endl
				<< "	'DisplayTree',	'DisplayNode',	'UpdateNode',	or 'end' to exit the program." << endl;
			cin >> input;
		}
	}
	
	return 0;
}
