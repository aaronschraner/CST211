/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  9, 2015
 * Last Modified:     November  9, 2015
 * Lab Number:        3 Freecell
 * Filename:          Deck.cpp
 * 
 ********************************************************************************/
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

#define SHUFFLE_ITERATIONS 10000

/********************************************************************************
 * Deck ();
 * 	Purpose: 
 * 		desfault constructor for deck class
 * 		Creates a full deck with 13 cards each in 4 suits
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		constructs full deck of cards
 * 	
 ********************************************************************************/
Deck::Deck ():
	cards(52,0)
{
	for(int suit=0; suit<4; suit++)
		for(int value=1; value < 14; value++)
			cards[suit*13+value-1] = Card(suit, value);
}

/********************************************************************************
 * void shuffle ();
 * 	Purpose: 
 * 		randomly shuffle the deck
 * 		works by swapping random numbers SHUFFLE_ITERATIONS times
 * 	
 * 	Entry: 
 * 		SHUFFLE_ITERATIONS: how many times random cards should be swapped
 * 	
 * 	Exit: 
 * 		shuffles the deck
 * 	
 ********************************************************************************/
void Deck::shuffle ()
{
	for(int i=0; i<SHUFFLE_ITERATIONS; i++)
	{
		srand(time(NULL) + i);
		swap(cards[rand()%52], cards[i%52]);
	}

}

/********************************************************************************
 * void display(std::ostream& os=std::cout);
 * 	Purpose: 
 * 		display the deck of cards
 * 	
 * 	Entry: 
 * 		os: the output stream to use
 * 		(in case you want to write to a file instead)
 * 	
 * 	Exit: 
 * 		displays deck in neatly formatted table
 * 	
 ********************************************************************************/
void Deck::display(std::ostream& os)
{
	for(int x=0; x < 13; x++)
	{
		for(int y=0; y < 4; y++)
			os << cards[y*13+x];
		os << std::endl;
	}
}

/********************************************************************************
 * Card& operator[](int index);
 * 	Purpose: 
 * 		Index operator for deck class
 * 		access the <index>th card in the deck
 * 	
 * 	Entry: 
 * 		index: the index of the card to be accessed
 * 	
 * 	Exit: 
 * 		returns a reference to the card
 * 	
 ********************************************************************************/
Card& Deck::operator[](int index)
{
	return cards[index];
}
