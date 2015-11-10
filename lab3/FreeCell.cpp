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

/********************************************************************************
 * void initGame ();
 * 	Purpose: 
 * 		Initialize the freecell game
 * 		- shuffle the deck
 * 		- deal the cards out
 * 		- show a welcome message
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		game is ready to play
 * 	
 ********************************************************************************/
void FreeCell::initGame ()
{
	//shuffle the deck
	gameDeck.shuffle();

	//push the cards into the play area
	for(int i=0; i<52; i++)
		playArea[i%NUM_PLAYCELLS].Push(gameDeck[i]);

	//show a welcome message
	showIntro();
}

/********************************************************************************
 * FreeCell();
 * 	Purpose: 
 * 		default constructor for freecell class
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		Initializes freeCells, foundations (home cells), and play cells
 * 	
 ********************************************************************************/
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
		case 1: return 'S';
		case 2: return 'D';
		case 3: return 'C';
		default: return 'X';
	}
}

/********************************************************************************
 * void displayUI(std::ostream& os = std::cout) const;
 * 	Purpose: 
 * 		Display the user interface for the game
 * 		First drawing free cells, then home cells, then the play area
 * 	
 * 	Entry: 
 * 		os: the output stream to use (defaults to cout)
 * 	
 * 	Exit: 
 * 		prints the current game
 * 	
 ********************************************************************************/
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

	//Main play cells
	os << setw(45) << right << "--Play cells--" << endl;

	//create an array of iterators for the card stacks
	Array<Iterator<Card>> iterators(NUM_PLAYCELLS,0);

	//draw the numbers for card stacks
	os << setw(20) << right << ' ';
	for(int i=0; i<NUM_PLAYCELLS; i++)
	{
		iterators[i] = playArea[i].startIterator();
		os << "   " << i << "   ";
	}
	os << endl;

	//iterate through the stacks breadth-first, displaying one card at a time.
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

/********************************************************************************
 * bool cardExists(CardLocation cl) const ;
 * 	Purpose: 
 * 		Find if there is a card in existence at the location specified
 * 		by <cl>.
 * 	
 * 	Entry: 
 * 		cl: the location to look for a card in
 * 	
 * 	Exit: 
 * 		returns true if there is a card at that spot in the game
 * 	
 ********************************************************************************/
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

/********************************************************************************
 * Card getCard(CardLocation location);
 * 	Purpose: 
 * 		Get a copy of the card at a given location
 * 		MAKE SURE YOU CHECK THAT IT EXISTS FIRST
 * 	
 * 	Entry: 
 * 		location: the place in the game to find the card
 * 	
 * 	Exit: 
 * 		returns a copy of the card at that location
 * 	
 ********************************************************************************/
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

/********************************************************************************
 * bool canMove(CardLocation src, CardLocation dest);
 * 	Purpose: 
 * 		Find if a card can be moved to a given spot based on the rules
 * 		of FreeCell.
 * 	
 * 	Entry: 
 * 		src: a CardLocation for the card being moved
 * 		dest: a CardLocation for where the card will go
 * 	
 * 	Exit: 
 * 		returns true if the card can be moved
 * 	
 ********************************************************************************/
bool FreeCell::canMove(CardLocation src, CardLocation dest)
{
	Card srcCard = getCard(src);
	switch(dest.field)
	{
		case CardLocation::_HomeCells:
			//can only move if card being moved is one greater than card being covered
			return ((foundations[dest.index].isEmpty() || srcCard.getNumber() == foundations[dest.index].Peek().getNumber() + 1 )&&
					(srcCard.getSuit() == dest.index));

			//can only be moved if free cell is empty
		case CardLocation::_FreeCells:
			return freeCells[dest.index].getNumber() == 0;

			//can only be moved if either the stack is empty or the card is one less than the one 
			//being covered with a different color.
		case CardLocation::_PlayCells:
			{
				//return if the stack is empty
				Stack<Card>& stackref = playArea[dest.index];
				if (stackref.isEmpty())
					return true;
				else
				{
					//return true if the criteria are met
					Card under = stackref.Peek();
					return under.getNumber() == srcCard.getNumber() + 1 && (srcCard.getSuit() ^ under.getSuit()) & 1;
				}
			}


	}
	return 0;
			
}

/********************************************************************************
 * bool tryMove(CardLocation src, CardLocation dest);
 * 	Purpose: 
 * 		attempt to move a card from <src> to <dest>
 * 		return 0 if it succeeds, 1 if it doesn't.
 * 	
 * 	Entry: 
 * 		src: the location of the card to be moved
 * 		dest: the place it should be moved to
 * 	
 * 	Exit: 
 * 		returns true if moving failed
 * 		false if it succeeded
 * 	
 ********************************************************************************/
bool FreeCell::tryMove(CardLocation src, CardLocation dest)
{
	Card moveCard;
	
	//make sure the card being moved exists
	if(!cardExists(src))
	{
		cout << "Source card doesn't exist." << endl;
		return 1;
	}

	//try to move the card
	cout << "Trying to move card " << getCard(src);

	//say what card is being covered if applicable
	if (cardExists(dest))
		cout << "onto " << getCard(dest);

	cout << endl;

	//if the move is against the rules, return failure
	if(!canMove(src, dest))
	{
		cout << "Moving card here violates rules." << endl;
		return 1;
	}

	//get a copy of the card and remove it from its source location
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

	//add the card copy to the destination
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

/********************************************************************************
 * bool gameOver() const;
 * 	Purpose: 
 * 		return true if the player has won the game
 * 	
 * 	Entry: 
 * 		Depends _ONLY_ on the home stacks
 * 		It does NOT do the magic thing that windows solitaire does
 * 		where it moves all the cards onto the pile if you've already arranged
 * 		them in the right order in the play area
 * 	
 * 	Exit: 
 * 		returns true if the game has ended
 * 	
 ********************************************************************************/
bool FreeCell::gameOver() const
{
	//add up all the numbers in the home cells
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

/********************************************************************************
 * void showIntro(std::ostream& os = std::cout) const;
 * 	Purpose: 
 * 		Show a text introduction to the game and explain how it is played.
 * 	
 * 	Entry: 
 * 		os: the output stream to use
 * 	
 * 	Exit: 
 * 		shows the intro and exits
 * 	
 ********************************************************************************/
void FreeCell::showIntro(std::ostream& os ) const
{
	os << "Welcome to FreeCell!" << endl;
	os << "Enter a card source and place to move it." << endl;
	os << "Enter the source and destination as space-separated sets of characters and numbers." << endl;
	os << "The characters for each field are 'f' for free cells, 'h' for home cells, and 'p' for play cells." << endl;
	os << "Example: to move the bottom card in the 0th column of the play cells to the 2nd free cell spot, you would enter" << endl;
	os << "\tp 0 f 2" << endl;
}
