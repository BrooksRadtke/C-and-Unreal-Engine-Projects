#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{ 10, 20, 30 };

	cout << " Initial vector: ";
	for (auto x : v)
	{
		cout << x << ' ';
	}
	cout << '\n';

	// Example of out of bounds index
	cout << " Vector size: " << v.size() << "\n\n";

	cout << " Trying: v[6] = 64; \n\n";
	v[6] = 64;

	cout << " Reading v[6]: " << v[6] << '\n';
}