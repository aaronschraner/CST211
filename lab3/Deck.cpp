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

//TODO: make method comment blocks
Deck::Deck ():
	cards(52,0)
{
	for(int suit=0; suit<4; suit++)
		for(int value=1; value < 14; value++)
			cards[suit*13+value-1] = Card(suit, value);
}

//TODO: make method comment blocks
void Deck::shuffle ()
{
	for(int i=0; i<SHUFFLE_ITERATIONS; i++)
	{
		srand(time(NULL) + i);
		swap(cards[rand()%52], cards[i%52]);
	}

}

void Deck::display(std::ostream& os)
{
	for(int x=0; x < 13; x++)
	{
		for(int y=0; y < 4; y++)
			os << cards[y*13+x];
		os << std::endl;
	}
}
Card& Deck::operator[](int index)
{
	return cards[index];
}
