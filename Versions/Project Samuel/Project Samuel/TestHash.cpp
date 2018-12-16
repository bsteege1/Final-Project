#include <iostream>
#include <string>
#include <functional>

void asldfj()
{
	std::string str = "Hello World";
	std::hash<std::string> hasher;
	auto hashed = hasher(str); //returns std::size_t
	std::cout << hashed << '\n'; //outputs 2146989006636459346 on my machine
	//return 0;
}