#include <iostream>
#include "Solitaire.h"

using namespace std;

void HandleMove(Solitaire& game);
void HandleMoveToAnswer(Solitaire& game);
void ClearScreen();

int main(int argc, char** argv)
{
	Solitaire game = Solitaire();
	game.PrintAllDetails();

	bool running = true;
	
	do
	{
		char option = ' ';
		cout << endl << endl;
		cout << "1. Move card between rows\n";
		cout << "2. Move to answers\n";
		cout << "3. Deal\n";
		cout << "0. Quit\n";
		cout << "Please enter option: ";
		cin >> option;

		if (game.GameCompleted())
		{
			ClearScreen();
			cout << "\n\n\n\t\t\t CONGRATULATIONS!! YOU WIN!!\n\n";
			cin.get();
			running = false;
		}

		else
		{
			switch ((int)option)
			{
			case 48:
				running = false;
				break;
			case 49:
				HandleMove(game);
				break;
			case 50:
				HandleMoveToAnswer(game);
				break;
			case 51:
				game.Deal(3);
				break;
			default:
				cout << "\nInvalid option. Please try again.";
				cin.ignore(80, '\n');
				break;
			}
			ClearScreen();
			game.PrintAllDetails();
		}
	}
	while (running);
	return 0;
}

void HandleMove(Solitaire& game)
{
	// Setting card placements
	char from = '0', to = '0';
	cout << endl << endl;
	cout << "From (7 per deck):\n";
	cin >> from;
	cout << "To: \n";
	cin >> to;

	if (((int)from >= 48 && (int)from <= 55) &&
		((int)from >= 48 && (int)to <= 54))
	{
		game.MakeMoveRowToRow((int)from - 48, (int)to - 48);
	}

	else
	{
		cout << "Invalid input";
		cin.get();
		cin.get();
	}
}

void ClearScreen()
{
#ifdef __linux__
	system("clear");
#elif _WIN32
	system("cls");
#endif
}