#pragma once
#include <iostream>

#ifdef _WIN32
#include<windows.h>
const static int BLACK = 0;
const static int BLUE = 9;
const static int RED = 12;
const static int WHITE = 15;
#elif __linux__
#include "stdlib.h"
#endif

class Card
{
public:
	Card(void);
	Card(char rank, char suit);
	~Card(void);

	void Flip();
	bool GetIsFaceUp();

	int GetSolitaireValue();
	char getCardSuit();
	char GetCardRank();

	friend std::ostream& operator << (std::ostream& os, Card& c);

	// Use to navigate up/down cards in row

	Card* parent;
	Card* child;

private:
	char rank;
	char suit;
	bool isFaceUp;
};