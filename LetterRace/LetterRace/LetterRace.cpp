#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	const int size = 60;

	cout << "Enter a letter you would like to race against: \n";
	
	char x;
	cin >> x;
	int position = size / 2;

	while (true)
	{
		cout << "|START|";
		
		for (int i = 0; i < size; i++)
		{
			if (i == position)
			{
				cout << x;
			}
			else
			{
				cout << " ";
			}
		}

		cout << "|FINISH|\n -cue cheering from audience-" << endl;

		int move = rand() % 3 - 1;
		position = position + move;

		if (position < 1)
		{
			cout << "Oh no! You lost the race to " << x << "!" << endl;
			break;
		}

		if (position > size - 1)
		{
			cout << "Horray! You beat that " << x << " in a good 'ol fashion of wit and whimsey!" << endl;
			break;
		}

		for (int sleep = 0; sleep < 1000000; sleep++);
	}
	return 0;
}