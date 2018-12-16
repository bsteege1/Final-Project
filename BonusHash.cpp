//Final-Project
//BonusHash.cpp
//COSC 2030
//Brandon Steege and Leonardo Garcia
//12/15/18

#include <string>
#include <iostream>

using namespace std;

//MyHash converts characters to their hexadecimal values.
//Their hexadecimal value is then % 5.
//They are then appended to a string for output.
//Output is equal in length to input.

string MyHash(string input) {
	string output = "";
	for (int i = 0; i < input.size(); i++)
	{
		long hex = input.at(i);
		long mod = hex % 5;
		string converted = to_string(mod);
		output += converted;
	}
	return output;
}


//main takes in an input from the user.
//main then calls MyHash and hashes the input.
//main outputs the hash
int main()
{
	string input;
	string hashed;

	cout << "Enter an 8 character string to hash.\n" << endl;
	cin >> input;

	hashed = MyHash(input);

	cout << "The hash of: " << input << " is: " << hashed << endl;

	system("PAUSE");
	return 0;
}

