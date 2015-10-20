/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 19, 2015
 * Last Modified:     October 19, 2015
 * Lab Number:        1
 * Filename:          Minesweeper.h
 * 
 * Class: Minesweeper
 * 
 * Methods: 
 *      Minesweeper (int rows, int cols, int mines):
 *         Constructor for minesweeper (creates a <rows> by <cols> board and fills with <mines> mines
 * 
 *     gameOver()  bool const:
 *         Returns true if the game has ended
 * 
 *      void click (int x, int y):
 *         Click / unhide the cell at (x, y) in the minesweeper board
 * 
 *      void flag (int x, int y):
 *         Put a flag on the cell at (x, y) in the minesweeper board
 * 
 *      void gameLoop ():
 *         Prompts for an action and coords and does the action at those coords
 *
 *      void print():
 *		   Print some statistics about the game followed by an ASCII art version of the board
 * 
 * 
 ********************************************************************************/
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <iostream>
#include "Board.h"

class Minesweeper
{
    private:
        // the Minesweeper board with all the cells in it
		Board game;

		// stores any win/lose exceptions that come up during click()ing or flag()ing
		Board::GameOver* gameOverCode;

    public:
		// constructor
        Minesweeper (int rows, int cols, int mines);

		// find out if the game has ended yet
        bool gameOver()  const;

		// click/uncover the cell at (x, y)
        void click (int x, int y);

		// flag/unflag the cell at (x, y) (toggles flag state)
        void flag (int x, int y);

		//main game routine to be used by main()
        void gameLoop ();

		//print game statistics and an ASCII art depiction of the game board
		void print();



};
#endif

