//https://stackoverflow.com/questions/16075271/hashing-a-string-to-an-integer-in-c

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

int hashed(string str)
{
	hash<string> hasher;
	auto hashed = hasher(str);
	return hashed;
}

void genRand(string random)
{
	int output = 0;
	srand(time(0));
	for (int z = 0; z < 8; z++)
	{
		random += genRandom();
	}
	cout << "\nBefore hash: " << random << endl;
	output = hashed(random);
	cout << "After Hash: " << output << endl;
}
