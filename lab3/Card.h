/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  9, 2015
 * Last Modified:     November  9, 2015
 * Lab Number:        3 Freecell
 * Filename:          Card.h
 * 
 * Class: Card
 * 
 * Methods: 
 *      Card (CardSuit suit, int value):
 *         Constructor given suit and value
 * 
 *     int getSuit ():
 *         returns card suit
 * 
 *     int getNumber ():
 *         returns card number value
 * 
 * 
 ********************************************************************************/
#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card
{
    private:
		//Heart = 0, Spade = 1, Diamond = 2, Club = 3
		int suit;
		int value; //ace is 1, J Q K = 11 12 13

    public:

        //TODO: brief description
        Card (int suit, int value);
		Card(const Card& c);
		Card();
		Card& operator=(const Card& c);

		friend std::ostream& operator<<(std::ostream& os, const Card& c);

        //TODO: brief description
        int getSuit () const;

        //TODO: brief description
        int getNumber () const;

};
#endif

