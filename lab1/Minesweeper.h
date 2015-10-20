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
 * 
 ********************************************************************************/
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <iostream>
#include "Board.h"

class Minesweeper
{
    private:
        //TODO: add member variables
		Board game;
		Board::GameOver* gameOverCode;

    public:
        //TODO: brief description
        Minesweeper (int rows, int cols, int mines);

        //TODO: brief description
        bool gameOver()  const;

        //TODO: brief description
        void click (int x, int y);

        //TODO: brief description
        void flag (int x, int y);

        //TODO: brief description
        void gameLoop ();

		void print();



};
#endif

