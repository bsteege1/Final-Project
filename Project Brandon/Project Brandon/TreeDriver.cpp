#include "NodeData.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
	nodeData free;
	nodeData tree;
	nodeData test;
	vector <struct bst> v1;
	MakeNode(v1, free);
	Insert(v1, tree);
	Insert(v1, test);
	//Insert(v1, 40);
	//Insert(v1, 35);
	//Insert(v1, 16);
	//Insert(v1, 7);

	//nodeData test;
	system("pause");
	return 0;
}