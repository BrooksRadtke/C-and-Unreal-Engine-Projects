#include <iostream>
#include <cassert>
#include <map>
#include <string>
using namespace std;

int main()
{
	// create an empty map
	map<int, string> numbers{};

	// verify that the map is empty
	assert(numbers.empty());

	// create some number-pronunciations in the map
	numbers[1] = "one";
	numbers[2] = "two";
	numbers[10] = "ten";
	numbers[6] = "six";
}