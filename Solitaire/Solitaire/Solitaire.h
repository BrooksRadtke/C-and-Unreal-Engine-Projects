#pragma once

#include <iostream>
#include <vector>

#include "Deck.h"
#include "Card.h"
#include "TableCard.h"

const static int TABLE_SIZE = 7;

class Solitaire
{
public:
	Solitaire(void);
	~Solitaire(void);

	void PopulateTable(void);
	void Deal(int numToDeal = 1);

	// Functions for validating and moving cards
	void MakeSuitMove(int from);
	void MakeMoveBetweenRows(int from, int to);
	void MakeMoveDeckToRow(int to);
	void MakeMoveRowToRow(int from, int to);
	bool ValidMove(int from, int to);
	bool ValidRowToRowMove(Card* fromCard, int to);
	bool ValidSuitMove(int from);

	// Checks to see if all answer sections full
	bool GameCompleted();

	// Methods for printing card details
	void PrintAllDetails(void);
	void PrintSuitDetails(void);
	void PrintDeckDetails(void);

private:
	TableCard _deck;
	TableCard _discardedCards;
	std::vector<TableCard> _tableCards;

	//Destination of cards. Player wins when all filled
	std::vector<TableCard> _suitCards;
};