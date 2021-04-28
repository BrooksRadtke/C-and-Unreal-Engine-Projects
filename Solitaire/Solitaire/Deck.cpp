#include "Deck.h"

Deck::Deck(void) :
	currentIndex(0)
{
	// Populate with random
	srand((unsigned)time(0));
	Populate();
}

Deck::~Deck(void)
{
}

void Deck::Populate()
{
	int index = 0;
	for (int i = 0; i < SUIT_SIZE; i++)
	{
		for (int j = 0; j < RANK_SIZE; j++)
		{
			_deck[index] = Card(RANKS[j], SUITS[i]);
			index++;
		}
	}
}

void Deck::Shuffle()
{
	int max = SUIT_SIZE * RANK_SIZE;

	for (int i = 0; i < max - 1; i++)
	{
		int randNum = rand() % 52;
		std::swap(_deck[i], _deck[randNum]);
	}
}

void Deck::PrintDeck(void)
{
	int max = SUIT_SIZE * RANK_SIZE;

	for (int i = 0; i < max; i++)
	{
		if (i % 13 == 0)
		{
			std::cout << "\n\n";
		}
	}
}

void Deck::PopulateVector(TableCard& aDeck)
{
	int max = SUIT_SIZE * RANK_SIZE;
	aDeck.Clear();

	for (int i = 0; i < max; i++)
	{
		aDeck.PushValueCopy(_deck[i]);
	}
}