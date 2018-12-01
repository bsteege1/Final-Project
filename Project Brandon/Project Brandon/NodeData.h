#include "RandomString.h"
#include <string>
#include <vector>
#include <functional>
using namespace std;

class nodeData
{
	string ID = NULL;
	string ParentID = NULL;
	string Event = NULL;
	string Rhash = NULL;
	string Lhash = NULL;
	string Rhist = NULL;
	string Lhist = NULL;
	vector<string> RightHist;
	vector<string> LeftHist;

public:
	void genRand(string random);
	string hashed(string data);
};

string hashed(string s)
{
	std::hash<std::string> hash_fn;
	size_t hash = hash_fn(s);
	string middle;
	middle = hash;
	return middle;
}

void genRand(string random)
{
	srand(time(0));
	for (int z = 0; z < 8; z++)
	{
		 random += genRandom();
	}
	cout << "\nBefore hash: " << random << endl;
	hashed(random);
	cout << "After Hash: " << random << endl;
}


