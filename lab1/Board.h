/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 17, 2015
 * Last Modified:     October 17, 2015
 * Lab Number:        1
 * Filename:          Board.h
 * 
 * Class: Board
 * 
 * Methods: 
 *      void generateNeighbors ():
 *         calculates the number of adjacent mines for each cell
 * 
 *      void uncoverArea (int x, int y):
 *         Make all surrounding unmined cells visible
 * 
 *      void print ():
 *         display the board
 * 
 *      void click (int x, int y):
 *         Try clicking the selected tile
 * 
 *      void flag (int x, int y):
 *         flag the selected cell
 * 
 * 
 ********************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "array2D.h"
#include "Cell.h"
class Board
{
    private:
		//the board containing all the minesweeper cells
        Array2D <Cell> board;

		//the number of mines, rows, and columns in the board
		int mines;
		int rows;
		int cols;


    public:
		//calculate the number of adjacent mines for each cell and store them in the cells
        void generateNeighbors ();

		//uncover a continuous area with no adjacent mines (works the same as in normal minesweeper)
        void uncoverArea (int x, int y);

		//print the minesweeper board in ASCII art
        void print ();

		//click (uncover) the selected cell
        void click (int x, int y);

		//flag the cell at (x, y)
        void flag (int x, int y);
		
		//find the number of unflagged mines left on the board
		int getRemainingMines();

		//find the number of mines on the board that the user has flagged
		int getFlaggedMines();

		//constructor given board dimensions and number of randomly placed mines
		Board(int rows, int cols, int mines);

		//for use with end-game exception throwing
		enum GameOver
		{
			_LOST,
			_WON
		};

};
#endif

