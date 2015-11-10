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

//TODO: make method comment blocks
Card::Card (int suit, int value):
	suit(suit),value(value)
{
}

Card::Card ():
	suit(0),value(0)
{
}

//TODO: make method comment blocks
int Card::getSuit () const
{
	return suit;
}

//TODO: make method comment blocks
int Card::getNumber () const
{
	return value;
}

//displays cards in [suit number] format where suit 
//is a letter and number is either a number or A,J,Q,or K
ostream& operator<<(ostream& os, const Card& c)
{
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

Card::Card(const Card& c):
	suit(c.suit), value(c.value)
{
}

Card& Card::operator=(const Card& c)
{
	suit=c.suit;
	value = c.value;
	return *this;
}
