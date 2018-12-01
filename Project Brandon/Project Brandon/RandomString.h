//http://www.cplusplus.com/forum/windows/88843/

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


