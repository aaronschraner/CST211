/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  9, 2015
 * Last Modified:     November  9, 2015
 * Lab Number:        3 FreeCell
 * Filename:          FreeCell.cpp
 * 
 ********************************************************************************/
#include "FreeCell.h"
#include "Deck.h"
#include "LinkedList.h"
#include "Array.h"
#include "Stack.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::ostream;
using std::left;
using std::setw;
using std::endl;
using std::right;
using std::istream;
using std::string;
using std::cout;

//TODO: make method comment blocks
void FreeCell::initGame ()
{
	//shuffle the deck
	gameDeck.shuffle();

	//push the cards into the play area
	for(int i=0; i<52; i++)
		playArea[i%NUM_PLAYCELLS].Push(gameDeck[i]);
	showIntro();
}

FreeCell::FreeCell():
	freeCells(NUM_FREECELLS,0),
	foundations(4, 0),
	playArea(NUM_PLAYCELLS,0)
{

}

char suitChar(int suit)
{
	switch(suit)
	{
		case 0: return 'H';
		case 1: return 'D';
		case 2: return 'S';
		case 3: return 'C';
		default: return 'X';
	}
}

void FreeCell::displayUI(ostream& os) const
{
	os << "H - red heart, D - black diamond, S - red spade, C - black club" << endl;
	//Free Cells
	os << setw(30) << left << "Free cells:" << setw(40) << right << "Home cells:" << endl;
	for(int i=0; i<NUM_FREECELLS; i++)
		os << i << freeCells[i];

	//Foundations (home cells)
	os << setw(30) << right;
	for(int i=0; i<4; i++)
		if(foundations[i].isEmpty())
			os << i << "[" << suitChar(i) << "---] ";
		else
			os << foundations[i].Peek();
	os << endl << endl;

	os << setw(45) << right << "--Play cells--" << endl;

	Array<Iterator<Card>> iterators(NUM_PLAYCELLS,0);
	os << setw(20) << right << ' ';
	for(int i=0; i<NUM_PLAYCELLS; i++)
	{
		iterators[i] = playArea[i].startIterator();
		os << "   " << i << "   ";
	}
	os << endl;

	bool levelHasCard = 1;
	for(int y = 0; y < 52 && levelHasCard; y++)
	{
		os << setw(20) << right << ' ';
		levelHasCard=0;
		for(int x=0; x < NUM_PLAYCELLS; x++)
		{
			if(iterators[x].isValid())
			{
				os << *(iterators[x]);
				levelHasCard = 1;
				++iterators[x];
			}
			else if(y==0)
				os << "[----] ";
			else
				os << "       ";
		}
		os << endl;
	}
}

bool FreeCell::cardExists(CardLocation cl) const
{
	switch(cl.field)
	{
		case CardLocation::_HomeCells:
			return cl.index < 4 && cl.index >= 0 && !foundations[cl.index].isEmpty();
		case CardLocation::_FreeCells:
			return cl.index >= 0 && cl.index < NUM_FREECELLS && freeCells[cl.index].getNumber() > 0;
		case CardLocation::_PlayCells:
			return cl.index >= 0 && cl.index < NUM_PLAYCELLS && !playArea[cl.index].isEmpty();
	}
}

Card FreeCell::getCard(CardLocation location)
{
	//assumes you already made sure it exists
	switch(location.field)
	{
		case CardLocation::_HomeCells:
			return foundations[location.index].Peek();
		case CardLocation::_FreeCells:
			return freeCells[location.index];
		case CardLocation::_PlayCells:
			return playArea[location.index].Peek();
	}
}
bool FreeCell::canMove(CardLocation src, CardLocation dest)
{
	Card srcCard = getCard(src);
	switch(dest.field)
	{
		case CardLocation::_HomeCells:
			return (srcCard.getNumber() == foundations[dest.index].Peek().getNumber() + 1 &&
					(srcCard.getSuit() == dest.index));

		case CardLocation::_FreeCells:
			return freeCells[dest.index].getNumber() == 0;
		case CardLocation::_PlayCells:
			{
				Stack<Card>& stackref = playArea[dest.index];
				if (stackref.isEmpty())
					return true;
				else
				{
					Card under = stackref.Peek();
					return under.getNumber() == srcCard.getNumber() + 1 && (srcCard.getSuit() ^ under.getSuit()) & 1;
				}
			}


	}
	return 0;
			
}
//0 for success
bool FreeCell::tryMove(CardLocation src, CardLocation dest)
{
	Card moveCard;
	if(!cardExists(src))
	{
		cout << "Source card doesn't exist." << endl;
		return 1;
	}

	cout << "Trying to move card " << getCard(src);
	if (cardExists(dest))
		cout << "onto " << getCard(dest);
	cout << endl;
	if(!canMove(src, dest))
		return 1;

	switch(src.field)
	{
		case CardLocation::_HomeCells:
			moveCard = foundations[src.index].Pop();
			break;
		case CardLocation::_FreeCells:
			moveCard = freeCells[src.index];
			{
				Card blankCard;
				freeCells[src.index] = blankCard;
			}
			break;
		case CardLocation::_PlayCells:
			moveCard = playArea[src.index].Pop();
			break;
	}

	switch(dest.field)
	{
		case CardLocation::_HomeCells:
			foundations[dest.index].Push(moveCard);
			break;
		case CardLocation::_FreeCells:
			freeCells[dest.index] = moveCard;
			break;
		case CardLocation::_PlayCells:
			playArea[dest.index].Push(moveCard);
			break;
	}

	return 0;
}

bool FreeCell::gameOver() const
{
	int cardcount=0;
	for(int i=0; i<4; i++)
		for(Iterator<Card> it = foundations[i].startIterator();
				it.isValid(); ++it)
			cardcount++;
	return cardcount==52;
}

CardLocation::Field getField(char c)
{
	switch(c)
	{
		case 'h': return CardLocation::_HomeCells;
		case 'f': return CardLocation::_FreeCells; 
		case 'p': return CardLocation::_PlayCells;
	}
}

void FreeCell::showIntro(std::ostream& os ) const
{
	os << "Welcome to FreeCell!" << endl;
	os << "Enter a card source and place to move it." << endl;
	os << "Enter the source and destination as space-separated sets of characters and numbers." << endl;
	os << "The characters for each field are 'f' for free cells, 'h' for home cells, and 'p' for play cells." << endl;
	os << "Example: to move the bottom card in the 0th column of the play cells to the 2nd free cell spot, you would enter" << endl;
	os << "\tp 0 f 2" << endl;
}
