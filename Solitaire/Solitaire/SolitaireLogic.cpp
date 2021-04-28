#include "Solitaire.h"
using namespace std;

Solitaire::Solitaire(void) :
	_deck(52), _discardedCards(52)
{
	// Uses deck class to populate solitaire deck
	// Randomize to shuffle the deck

	Deck deck = Deck();
	deck.Shuffle();
	deck.PopulateVector(_deck);

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		TableCard tableCard = TableCard(20);
		_tableCards.push_back(tableCard);
	}

	for (int i = 0; i < 4; i++)
	{
		TableCard suitCard = TableCard(13);
		_suitCards.push_back(suitCard);
	}
	PopulateTable();
}

Solitaire::~Solitaire(void)
{}

void Solitaire::PopulateTable(void)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		for (int j = 0; j < TABLE_SIZE - i; j++)
		{
			if (j == (TABLE_SIZE - i) - 1)
			{
				_deck.top().Flip();
			}

			_tableCards[j].Push(_deck.top());
			_deck.Pop();
		}
	}
}

void Solitaire::Deal(int numToDeal)
{
	int size = _deck.Size();
	
	for (int i = 0; i < size; i++)
	{
		if (_deck.top().GetIsFaceUp())
		{
			_deck.top().Flip();
			_discardedCards.Push(_deck.top());
			_deck.Pop();
		}
	}

	if (_deck.empty())
	{
		for (int i = _discardedCards.Size() - 1; i >= 0; i--)
		{
			_deck.Push(_discardedCards[i]);
		}

		_discardedCards.Clear();
	}

	int index = 0;
	
	for (int i = 0; i < numToDeal; i++)
	{
		index = _deck.Size() - i - 1;
		
		if (index >= 0)
		{
			_deck[index].Flip();
		}

		else
		{
			break;
		}
	}
}

void Solitaire::PrintSuitDetails()
{
	cout << "==============================================\n";

	for (int i = 0; i < _suitCards.size(); i++)
	{
		switch (i)
		{
		case 0:
			cout << "h : ";
			break;
		case 1:
			cout << "d : ";
			break;
		case 2:
			cout << "s : ";
			break;
		case 3:
			cout << "c : ";
			break;
		}

		for (int j = 0; j < _suitCards[j].Size(); j++)
		{
			if (&_suitCards[j][i] != NULL)
			{
				cout << _suitCards[j][i] << " ";
			}
			else
			{
				break;
			}
		}

		cout << endl;
	}

	cout << "==============================================\n";
	cout << endl;
}

void Solitaire::PrintDeckDetails()
{
	cout << "----------------------------------------------\n";
	cout << "|Deck: ";

	for (unsigned int i = 0; i < _deck.Size(); i++)
	{
		if (_deck[i].GetIsFaceUp())
		{
			cout << _deck[i] << " ";
		}
	}

	cout << "----------------------------------------------\n";
}

void Solitaire::PrintAllDetails()
{
	PrintDeckDetails();
	PrintSuitDetails();

	cout << "| 6 | \t | 5 | \t | 4 | \t | 3 | \t | 2 | \t | 1 | \t | 0 | \n";
	cout << "----- \t ----- \t ----- \t ----- \t ----- \t ----- \t ----- \n";

	int colMax = _tableCards.size();
	int rowMax = 0;

	for (int i = 0; i < colMax; i++)
	{
		if (_tableCards[i].Size() > rowMax)
		{
			rowMax = _tableCards[i].Size();
		}
	}

	for (int i = 0; i < rowMax; i++)
	{
		for (int j = colMax - 1; j >= 0; j--)
		{
			if (i >= _tableCards[j].Size())
			{
				cout << " \t ";
				continue;
			}

			if (_tableCards[j][i].GetIsFaceUp())
			{
				cout << " " << _tableCards[j][i] << " \t ";
			}

			else
			{
				cout << " " << (char)254 << " \t ";
			}
		}

		cout << endl << endl;
	}
}

bool Solitaire::ValidMove(int from, int to)
{
	// Start and end move
	if (from == to && from != 7)
	{
		return false;
	}

	Card* toCard = NULL;
	Card* fromCard = NULL;

	if (from == 7)
	{
		if (!_deck.top().GetIsFaceUp())
		{
			return false;
		}

		else
		{
			fromCard = &_deck.top();
		}
	}

	else
	{
		// Not valid if no card is being more from row
		if (!_tableCards[from].empty())
		{
			fromCard = &_tableCards[from].top();
		}

		else
		{
			return false;
		}
	}

	if (!_tableCards[from].empty())
	{
		toCard = &_tableCards[to].top();
	}

	// Move King to empty space
	if (_tableCards[to].empty())
	{
		if (fromCard->GetCardRank() == 'K')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (fromCard->GetSolitaireValue() == toCard->GetSolitaireValue() - 1)
	{
		// Assigning colors
		int toColor = 0, fromColor = 0;
		if (toCard->getCardSuit() == 'h' || toCard->getCardSuit() == 'd')
		{
			toColor = 0;
		}

		else
		{
			toColor = 1;
		}

		if (fromCard->getCardSuit() == 'h' || fromCard->getCardSuit() == 'd')
		{
			fromColor = 0;
		}

		else
		{
			fromColor = 1;
		}

		if (fromColor == toColor)
		{
			return false;
		}

		else
		{
			return true;
		}
	}

	return false;
}

bool Solitaire::ValidSuitMove(int from)
{
	Card* fromCard;
	
	if (from == 7)
	{
		if (!_deck.empty())
		{
			if (!_deck.top().GetIsFaceUp())
			{
				return false;
			}
			else
			{
				fromCard = &_deck.top();
			}
		}

		else
		{
			return false;
		}
	}
	else
	{
		if (!_tableCards[from].empty())
		{
			fromCard = &_tableCards[from].top();
		}
		else
		{
			return false;
		}
	}

	// Checks which suit the card is from
	char suit = fromCard->getCardSuit();
	int moveIndex = 0;

	switch (suit)
	{
	case 'h':
		moveIndex = 0;
		break;
	case 'd':
		moveIndex = 1;
		break;
	case 's':
		moveIndex = 2;
		break;
	case 'c':
		moveIndex = 3;
		break;
	default:
		break;
	}

	if (fromCard->GetSolitaireValue() == _suitCards[moveIndex].Size() + 1)
	{
		if (!_suitCards[moveIndex].Size() == 0)
		{
			if (fromCard->parent != NULL)
			{
				fromCard->parent->child = NULL;
			}

			fromCard->parent = &_suitCards[moveIndex].top();
			_suitCards[moveIndex].top().child = fromCard;
			fromCard->child = NULL;
		}

		if (from != 7)
		{
			TableCard::MoveBetween(_tableCards[from], _suitCards[moveIndex]);

			if (!_tableCards[from].top().GetIsFaceUp())
			{
				_tableCards[from].top().Flip();
			}
		}

		else
		{
			_suitCards[moveIndex].Push(_deck.top());
			_deck.Pop();
		}
	}

	return false;
}

void Solitaire::MakeSuitMove(int from)
{
	// validSuit move also makes move
	ValidSuitMove(from);
}

void Solitaire::MakeMoveBetweenRows(int from, int to)
{
	if (ValidMove(from, to))
	{
		if (!_tableCards[to].empty())
		{
			_tableCards[to].top().child = &_tableCards[from].top();
		}

		if (_tableCards[from].top().GetCardRank() != 'K')
		{
			_tableCards[from].top().parent = &_tableCards[to].top();
		}

		TableCard::MoveBetween(_tableCards[from], _tableCards[to]);

		if (!_tableCards[from].empty())
		{
			if (!_tableCards[from].top().GetIsFaceUp())
			{
				_tableCards[from].top().Flip();
			}
		}
	}
}

void Solitaire::MakeMoveDeckToRow(int to)
{
	if (ValidMove(7, to))
	{
		// Checks if slot is empty
		if (!_tableCards[to].empty())
		{
			_tableCards[to].top().child = &_deck.top();
		}

		// Checks if card is King
		if (_deck.top().GetCardRank() != 'K')
		{
			_deck.top().parent = &_tableCards[to].top();
		}

		_tableCards[to].Push(_deck.top());
		_deck.Pop();
	}
}

void Solitaire::MakeMoveRowToRow(int from, int to)
{
	if (from == 7)
	{
		MakeMoveDeckToRow(to);
		return;
	}
	else if (_tableCards[from].Size() == 0)
	{
		return;
	}

	Card* fromCard;
	fromCard = &_tableCards[from].top();

	if (fromCard->parent == NULL)
	{
		MakeMoveBetweenRows(from, to);
	}

	else
	{
		int pos = _tableCards[from].Size() - 1;
		bool checkParent = true;
		bool found = false;

		while (checkParent && !found)
		{
			if (ValidRowToRowMove(fromCard, to))
			{
				found = true;
			}
			else if (fromCard->parent == NULL)
			{
				checkParent = false;
			}
			else
			{
				fromCard = fromCard->parent;
				pos--;
			}
		}

		if (found)
		{
			bool hasChildren = true;

			if (fromCard->parent != NULL)
			{
				fromCard->parent->child = NULL;
			}

			while (hasChildren)
			{
				if (!_tableCards[to].empty())
				{
					fromCard->parent = &_tableCards[to].top();
					_tableCards[to].top().child = fromCard;
				}

				_tableCards[to].Push(*fromCard);

				_tableCards[from].RemoveAt(pos);
				fromCard = fromCard->child;

				pos++;
				if (fromCard == NULL)
				{
					hasChildren = false;
				}
			}
		}

		if (!_tableCards[from].empty())
		{
			if (!_tableCards[from].top().GetIsFaceUp())
			{
				_tableCards[from].top().Flip();
			}
		}
	}
}

bool Solitaire::ValidRowToRowMove(Card* fromCard, int to)
{
	Card* toCard = NULL;

	if (!_tableCards[to].empty())
	{
		toCard = &_tableCards[to].top();
	}

	// Move King to empty space
	if (_tableCards[to].empty())
	{
		if (fromCard->GetCardRank() == 'K')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (fromCard->GetSolitaireValue() == toCard->GetSolitaireValue() - 1)
	{
		int toColor = 0, fromColor = 0;

		if (toCard->getCardSuit() == 'h' || toCard->getCardSuit() == 'd')
		{
			toColor = 0;
		}
		else
		{
			toColor = 1;
		}

		if (fromCard->getCardSuit() == 'h' || fromCard->getCardSuit() == 'd')
		{
			fromColor = 0;
		}
		else
		{
			fromColor = 1;
		}

		if (fromColor == toColor)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	return false;
}

bool Solitaire::GameCompleted()
{
	for (int i = 0; i < _suitCards.size(); i++)
	{
		if(_suitCards[i].Size() < 13)
		{ 
			return false;
		}
	}

	return true;
}