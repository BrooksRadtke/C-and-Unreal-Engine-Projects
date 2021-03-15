#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ostream& operator << (ostream& os, const vector<int>& v)
{
	os << "[ ";
	for (auto x : v)
	{
		os << x << ' ';
	}
	os << ']';
	return os;
}

// Predicate/condition for removing elements
inline bool IsOdd(int x)
{
	return x % 2 == 1;
}

int main()
{
	vector<int> v{ 11, 22, 33, 44, 55, 66 };
	cout << " Intial vector: " << v << "\n\n";

	cout << " Removing the odd numbers from the vector.\n\n";

	// Use of Erase and Remove
	v.erase(remove_if(begin(v), end(v), IsOdd), end(v));

	cout << " Vector content after erase-remove: " << v << "\n\n";
}