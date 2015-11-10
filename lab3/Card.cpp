/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  9, 2015
 * Last Modified:     November  9, 2015
 * Lab Number:        3 Freecell
 * Filename:          Card.cpp
 * 
 ********************************************************************************/
#include "Card.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::ostream;
using std::setw;
using std::right;

/********************************************************************************
 * Card (int suit, int value);
 * 	Purpose: 
 * 		constructor given suit and rank
 * 		does exactly what it looks like
 * 	
 * 	Entry: 
 * 		suit: the suit of the new card
 * 		value: the rank of the new card
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
Card::Card (int suit, int value):
	suit(suit),value(value)
{
}

/********************************************************************************
 * Card();
 * 	Purpose: 
 * 		default constructor for card
 * 		sets value and rank to 0
 * 		note that card ranks are never below 1 unless the card is not really present
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
Card::Card ():
	suit(0),value(0)
{
}

/********************************************************************************
 * int getSuit () const;
 * 	Purpose: 
 * 		return the suit of the card
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 		returns the suit (suit)
 * 	
 ********************************************************************************/
int Card::getSuit () const
{
	return suit;
}

/********************************************************************************
 * int getNumber () const;
 * 	Purpose: 
 * 		return the rank of the card
 * 	
 * 	Entry: 
 * 	
 * 	Exit: 
 * 		returns rank of card (value)
 * 	
 ********************************************************************************/
int Card::getNumber () const
{
	return value;
}

/********************************************************************************
 * std::ostream& operator<<(std::ostream& os, const Card& c);
 * 	Purpose: 
 * 		stream output operator for card
 * 		outputs card in square brackets [] with suit on the left (H,S,D,C)
 * 		and rank/number on the right
 * 		ex: [S  8] (8 of spades)
 * 		does not currently do color, so please use your imagination
 * 	
 * 	Entry: 
 * 		os: the output stream to print to
 * 		c: the card to print
 * 	
 * 	Exit: 
 * 		returns a reference to os
 * 	
 ********************************************************************************/
ostream& operator<<(ostream& os, const Card& c)
{
	//displays cards in [suit number] format where suit 
	//is a letter and number is either a number or A,J,Q,or K
	if(c.value == 0)
		return os << "[----] ";
	os << '[';
	switch(c.suit)
	{
		case 0: os << 'H'; break;
		case 1: os << 'S'; break;
		case 2: os << 'D'; break;
		case 3: os << 'C'; break;
	}
	os << ' ' << setw(2) << right;
	switch(c.value)
	{
		case 1:  os << 'A'; break;
		case 11: os << 'J'; break;
		case 12: os << 'Q'; break;
		case 13: os << 'K'; break;
		default: os << c.value ; break;
	}
	os << "] ";
	return os;
}

/********************************************************************************
 * Card(const Card& c);
 * 	Purpose: 
 * 		copy constructor for card class
 * 		just copies suit and value
 * 	
 * 	Entry: 
 * 		c: the card to be copied
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
Card::Card(const Card& c):
	suit(c.suit), value(c.value)
{
}

/********************************************************************************
 * Card& operator=(const Card& c);
 * 	Purpose: 
 * 		assignment operator for card class
 * 		sets suit and value to match c's
 * 	
 * 	Entry: 
 * 		c: the card to be copied
 * 	
 * 	Exit: 
 * 	
 ********************************************************************************/
Card& Card::operator=(const Card& c)
{
	suit=c.suit;
	value = c.value;
	return *this;
}
