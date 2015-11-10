/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      November  9, 2015
 * Last Modified:     November  9, 2015
 * Lab Number:        3 FreeCell
 * Filename:          FreeCell.h
 * 
 * Class: FreeCell
 * 
 * Methods: 
 *     void initGame ():
 *         Shuffle the deck and deal cards
 * 
 * 
 ********************************************************************************/
#ifndef FREECELL_H
#define FREECELL_H
#include "Deck.h"
#include "Card.h"
#include "LinkedList.h"
#include "Array.h"
#include "Stack.h"
#define NUM_FREECELLS 4
#define NUM_PLAYCELLS 8

struct CardLocation
{
	enum Field
	{
		_HomeCells,
		_FreeCells,
		_PlayCells
	} field;
	int index;
};


class FreeCell
{
    private:
        Deck gameDeck;
		Array<Card> freeCells;
		Array<Stack<Card>> foundations;
		Array<Stack<Card>> playArea;

    public:
		FreeCell();
        void initGame ();
		void displayUI(std::ostream& os = std::cout) const;
		bool tryMove(CardLocation src, CardLocation dest);
		bool gameOver() const;
		void showIntro(std::ostream& os = std::cout) const;
		bool cardExists(CardLocation cl) const ;
		Card getCard(CardLocation location);
		bool canMove(CardLocation src, CardLocation dest);

};
#endif

