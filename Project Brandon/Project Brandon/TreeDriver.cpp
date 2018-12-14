#include "NodeData.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main() 
{
	Tree* Root = NULL;
	Root = new Tree;
	//initializeRoot(Root);
	cout << "Passed initilized " << endl;

	int count(0);

	fillLeft(Root);
	cout << "filled left!!" << endl;
	fillRight(Root);
	cout << "filled right!!" << endl;
	Print(Root);

	system("PAUSE");
}