#include "NodeData.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main() 
{
	Tree* Root = NULL;
	Root = new Tree;
	int count = 1;
	count = fillRow(Root, count);
	cout << "This is the count: " << count << endl;
	Print(Root);


	system("PAUSE");
}