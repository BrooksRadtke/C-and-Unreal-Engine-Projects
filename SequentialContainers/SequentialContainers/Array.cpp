#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

int main()
{
	std::array<int,6> a{ 11, 22, 33, 44, 55, 66 };

	cout << " std::array's elements: \n";
	for (auto x : a)
	{
		cout << ' ' << x;
	}
	cout << "\n\n";

	cout << " The array contains " << a.size() << " elements. \n\n";

	cout << " Please enter a number to search for: \n";
	int n{};
	cin >> n;

	auto it = find(begin(a), end(a), n);
	if (it != end(a))
	{
		cout << ' ' << n << " was found in the array. \n";
	}
	else
	{
		cout << " " << n << " was not found. \n";
	}
}