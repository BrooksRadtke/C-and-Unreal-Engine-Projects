#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// case-sensitive string comparison
inline bool EqualNoCase(const string& s1, const string& s2)
{
	return equal(begin(s1), end(s1), begin(s2), end(s2),
		[](char ch1, char ch2)
		{
			// Compare characters in lowercase
			return tolower(ch1) == tolower(ch2);
		});
}

int main()
{
	vector<string> v{ "Bob", "Lucy", "N64", "C++" };

	cout << " String vector contains: \n";
	for (const auto& s : v)
	{
		cout << " " << s << '\n';
	}
	cout << '\n';

	cout << " Please enter a string to search for: ";
	string s;
	cin >> s;
	cout << '\n';

	/*auto pos = find(begin(v), end(v), s);
	if (pos != end(v))
	{
		cout << ' ' << s << " was found in the vector.\n";
	}
	else
	{
		cout << " The vector doesn't contain " << s << " \n";
	}*/

	auto pos = find_if(begin(v), end(v), [&s](const auto& x)
		{
			return EqualNoCase(x, s);
		});
	if (pos != end(v))
	{
		cout << ' ' << s << " was found in the vector.\n";
	}
	else
	{
		cout << " The vector doesn't contain " << s << " \n";
	};
}