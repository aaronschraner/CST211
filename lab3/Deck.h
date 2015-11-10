/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  9, 2015
 * Last Modified:     November  9, 2015
 * Lab Number:        3 Freecell
 * Filename:          Deck.h
 * 
 * Class: Deck
 * 
 * Methods: 
 *      Deck ():
 *         default constructor (creates full deck of cards)
 * 
 *     void Shuffle ():
 *         Shuffle the cards in the deck
 * 
 * 
 ********************************************************************************/
#ifndef DECK_H
#define DECK_H
#include "Array.h"
#include "Card.h"

template <typename T>
void swap(T& lhs, T& rhs)
{
	T temp=lhs;
	lhs=rhs;
	rhs=temp;
}

class Deck
{
    private:
        //TODO: add member variables
		Array<Card> cards;

    public:
        //TODO: brief description
        Deck ();
		Card& operator[](int index);

        //TODO: brief description
        void shuffle ();
		void display(std::ostream& os=std::cout);

};
#endif

