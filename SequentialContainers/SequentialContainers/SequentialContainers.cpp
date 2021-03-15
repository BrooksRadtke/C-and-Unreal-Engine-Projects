#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// prints the data from the file
	std::vector<int> v{};

	std::ifstream inputFile{ "data.txt" };
	int n{};

	while (inputFile >> n)
	{
		v.push_back(n);
	}
	for (auto x : v)
	{
		std::cout << x << "\n";
	}

	// Stored strings
	vector<string> lines{};
	ifstream stringFile{ "string.txt" };
	string line{};
	while (getline(inputFile, line))
	{
		lines.push_back(line);
	}
	for (const auto& x : lines)
	{
		cout << x << '\n';
	}
}