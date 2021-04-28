#include "Card.h"

Card::Card(void)
{
}

Card::Card(char r, char s) :
	rank(r),
	suit(s),
	isFaceUp(false),
	child(NULL),
	parent(NULL)
{
}

Card::~Card(void)
{
}

void Card::Flip()
{
	isFaceUp = !isFaceUp;
}

char Card::GetCardRank()
{
	return rank;
}

// returns score value based on rank of cards
int Card::GetSolitaireValue()
{
	if (rank == 'A')
	{
		return 1;
	}
	else if (rank == 'T')
	{
		return 10;
	}
	else if (rank == 'J')
	{
		return 11;
	}
	else if (rank == 'Q')
	{
		return 12;
	}
	else if (rank == 'K')
	{
		return 13;
	}
	else
	{
		char c[] = { rank, '\0' };
		return atoi(c);
	}
}

std::ostream& operator << (std::ostream& os, Card& c)
{
#ifdef _WIN32
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (c.suit == 'c' || c.suit == 's')
	{
		SetConsoleTextAttribute(handle, BLUE);
	}

	else
	{
		SetConsoleTextAttribute(handle, RED);
	}

#elif __liux__
	if (c.suit == 'c' || c.suit == 's')
	{
		os << "\033[22;34m";
	}

	else
	{
		os << "\033[22;31m";
	}
	os << c.suit << c.rank;
	os << "\033[22;30m";
#endif
	return os;
}