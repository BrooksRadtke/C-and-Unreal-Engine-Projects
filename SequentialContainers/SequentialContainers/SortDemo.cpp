#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// Read lines from text file into std::vector
	vector<string> lines{};
	istream inputFile{ "string.txt" };
	string line{};
	
	while (getLine(inputFile, line))
	{
		lines.push_back(line);
	}

	// Sort the lines in the vector
	sort(begin(lines), end(lines));

	// Print the sorted lines
	for (const auto& x : lines)
	{
		cout << x << '\n';
	}
}