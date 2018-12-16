//Final-Project
//randomString.h
//COSC 2030
//Brandon Steege and Leonardo Garcia
//12/15/18

#ifndef RANDOMSTRING_H
#define RANDOMSTRING_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()  // Random string generator function.
{

	return alphanum[rand() % stringLength];
}

#endif
