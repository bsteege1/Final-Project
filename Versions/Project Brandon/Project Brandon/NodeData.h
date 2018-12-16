//https://stackoverflow.com/questions/16075271/hashing-a-string-to-an-integer-in-c
#ifndef NODEDATA_H
#define NODEDATA_H

#include "RandomString.h"
#include <string>
#include <vector>
#include <functional>
using namespace std;

class nodeData
{
	string ParentID = genRand("random");
	string Event = inputEvent();
	string ID = hashed(Event, ParentID);
	string Rhash = "";
	string Lhash = "";
	vector<string> *RightHist = new vector<string>;
	vector<string> *LeftHist = new vector<string>;
	//int identifer = 1;
	//string Rhist = "";
	//string Lhist = "";

public:
	string genRand(string random);
	string hashed(string one, string two);
	string inputEvent();
	string printNode();
	string getLhash();
	string getParentID();
};

string nodeData::printNode()
{
	string data = getParentID();
	return data;
}

string nodeData::getParentID()
{
	return ParentID;
}

string nodeData::getLhash()
{
	return Lhash;
}

string nodeData::inputEvent()
{
	string raw;
	cout << "Please enter an event up to 1024 characters long: " << endl;
	cin >> raw;
	if (raw.length() > 1024)
	{
		cout << "Please enter an event up to 1024 characters long: " << endl;
		cin >> raw;
	}

	return raw;
}

string nodeData::hashed(string one, string two)
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
	cout << characters << " characters" << endl;
	string hashedString = "";
	auto hashed = hasher(characters);
	hashedString = to_string(hashed);
	cout << hashedString << " hash" << endl;
	//system("pause");
	return hashedString;
}

string nodeData::genRand(string random)
{
	string output;
	srand(time(0));
	for (int z = 0; z < 8; z++)
	{
		output += genRandom();
	}
	return output;
}
#endif