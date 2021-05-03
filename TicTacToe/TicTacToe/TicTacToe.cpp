#include <iostream>
using namespace std;

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkWin();
void board();

int main()
{
	int player = 1, i, choice;

	char mark;
	
	do
	{
		board();
		player = (player % 2) ? 1 : 2;

		cout << "\n\tPlayer " << player << ", enter a number: ";
		cin >> choice;

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')
		{
			square[1] = mark;
		}

		else if (choice == 2 && square[2] == '2')
		{
			square[2] = mark;
		}

		else if (choice == 3 && square[3] == '3')
		{
			square[3] = mark;
		}

		else if (choice == 4 && square[4] == '4')
		{
			square[4] = mark;
		}

		else if (choice == 5 && square[5] == '5')
		{
			square[5] = mark;
		}

		else if (choice == 6 && square[6] == '6')
		{
			square[6] = mark;
		}

		else if (choice == 7 && square[7] == '7')
		{
			square[7] = mark;
		}

		else if (choice == 8 && square[8] == '8')
		{
			square[8] = mark;
		}

		else if (choice == 9 && square[9] == '9')
		{
			square[9] = mark;
		}

		else
		{ 
			cout << "Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}

		i = checkWin();

		player++;
	}
	while (i == -1);

	board();

	if (i == 1)
	{
		cout << "\n\t==>\aPlayer " << --player << "wins! ";
	}
	else
	{
		cout << "\n\t==>\aGame draw";
	}

	cin.ignore();
	cin.get();
	return 0;
}

// Function to return game status:
// 1 for game is over with result
// -1 for gmae is in progress
// 0 for game is over and no result

// Checks the values of each set of index elements in array
int checkWin()
{
	// Top row
	if (square[1] == square[2] && square[2] == square[3])
	{
		return 1;
	}

	// middle row
	else if (square[4] == square[5] && square[5] == square[6])
	{
		return 1;
	}

	// bottom row
	if (square[7] == square[8] && square[8] == square[9])
	{
		return 1;
	}

	// Left column
	if (square[1] == square[4] && square[4] == square[7])
	{
		return 1;
	}

	// Middle column
	if (square[2] == square[5] && square[5] == square[8])
	{
		return 1;
	}

	// Right column
	if (square[3] == square[6] && square[6] == square[9])
	{
		return 1;
	}

	// "Backslash" diagonal
	if (square[1] == square[5] && square[5] == square[9])
	{
		return 1;
	}

	// "Forward-slash" diagonal
	if (square[3] == square[5] && square[5] == square[7])
	{
		return 1;
	}

	// Results in DRAW!
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

// Method to draw board of tic tac toe with player's mark

void board()
{
	system("cls");
	cout << "\n\n\t Tic Tac Toe\n\n";

	cout << "\tPlayer 1 (X) - Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;

	cout << "\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;

	cout << "\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "\t\t     |     |     " << endl;
}