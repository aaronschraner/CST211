/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 19, 2015
 * Last Modified:     October 19, 2015
 * Lab Number:        1
 * Filename:          Minesweeper.cpp
 * 
 ********************************************************************************/
#include "Minesweeper.h"
#include <iostream>
#include "Board.h"

using namespace std;

/********************************************************************************
 * Minesweeper (int rows, int cols, int mines);
 * 	Purpose: 
 * 		Minesweeper constructor given the size of the board and number of mines
 * 	
 * 	Entry: 
 * 		rows: the number of rows to create the board with
 * 		cols: the number of columns to create the board with
 * 		mines: the number of mines to randomly place on the board (handled by Board class)
 * 	
 * 	Exit: 
 * 		Constructed minesweeper game of width <cols> and height <rows>
 * 		with <mines> mines in it
 * 	
 ********************************************************************************/
Minesweeper::Minesweeper (int rows, int cols, int mines):
	game(rows, cols, mines), gameOverCode(0)
{
    
}

/********************************************************************************
 * bool gameOver()  const;
 * 	Purpose: 
 * 		Returns true if the game has been won or lost, false if it is still
 * 		in progress.
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		see Purpose section
 * 	
 ********************************************************************************/
bool Minesweeper::gameOver()  const
{
    return !! gameOverCode;
}

/********************************************************************************
 * void click (int x, int y);
 * 	Purpose: 
 * 		Click (uncover) the cell at (x, y)
 * 		This version is different from the one in Board in that it handles
 * 		the exception thrown by Board::click() when a click ends the game
 * 	
 * 	Entry: 
 * 		x: the x coordinate of the cell being clicked
 * 		y: the y coordinate of the cell being clicked
 * 	
 * 	Exit: 
 * 		Can put an exception in gameOverCode that gets handled later
 * 	
 ********************************************************************************/
void Minesweeper::click (int x, int y)
{
	try
	{
		game.click(x, y);
	}
	catch (Board::GameOver go)
	{
		gameOverCode = new Board::GameOver(go);
	}
}

/********************************************************************************
 * void flag (int x, int y);
 * 	Purpose: 
 * 		Toggle the flag on the cell at (x, y)
 * 	
 * 	Entry: 
 * 		x: the x coordinate of the cell being flagged
 * 		y: the y coordinate of the cell being flagged
 * 	
 * 	Exit: 
 * 		Can put a game over exception in gameOverCode if you cover the
 * 		last mine in the game with a flag
 * 	
 ********************************************************************************/
void Minesweeper::flag (int x, int y)
{
	try
	{
		game.flag(x, y);
	}
	catch (Board::GameOver go)
	{
		gameOverCode = new Board::GameOver(go);
	}

}

/********************************************************************************
 * void print();
 * 	Purpose: 
 * 		Print the contents of the Minesweeper board
 * 		(with statistics on flagged and remaining unflagged mines)
 * 		Technically you can use that to cheat
 * 		you can also win by flagging every single cell
 * 		but hopefully nobody will do that
 * 		because that's not fun
 * 	
 * 	Entry: 
 * 		Nothing (calls Board::print() and uses member functions to determine
 * 		remaining mine count)
 * 	
 * 	Exit: 
 * 		Prints the number of flagged mines, remaining unflagged mines,
 * 		and an ASCII art depiction of the Minesweeper board
 * 	
 ********************************************************************************/
void Minesweeper::print()
{
	cout << "Remaining mines: " << game.getRemainingMines() << "   Flagged mines: " << game.getFlaggedMines() << endl;
	game.print();
}

/********************************************************************************
 * void gameLoop ();
 * 	Purpose: 
 * 		The main loop routine for the Minesweeper game
 * 		- Prints the state of the board in ASCII art
 * 		- Asks the user to either uncover or flag a cell
 * 		- does what the user asks
 * 		- Checks if the last move ended the game
 * 		- If it did, find out if the player won or lost
 * 		- print a victory/failure message depending on what happened
 * 		- deallocate gameOverCode
 * 	
 * 	Entry: 
 * 		Nothing (operates on constructed Minesweeper class and member variables)
 * 	
 * 	Exit: 
 * 		Designed to be called in a while (!gameOver()) loop
 * 		Cannot exit the game on its own, but can break such a while loop
 * 	
 ********************************************************************************/
void Minesweeper::gameLoop ()
{
	print();

	char action;
	int xclick, yclick;
	cout << "Enter either c or f followed by two numbers to [c]lick or [f]lag the cell at (x, y). Ex: c 9 3 <enter>\n> ";
	cin >> action >> xclick >> yclick;
	switch(action)
	{
		case 'c':
			click(xclick, yclick);
			break;
		case 'f':
			flag(xclick, yclick);
			break;
	}
	if(gameOver())
	{
		switch(*gameOverCode)
		{
			case Board::GameOver::_LOST:
				print();
				cout << "You stepped on a mine! You lose. " << endl;
				break;
			case Board::GameOver::_WON:
				cout << "You won!" << endl;
				print();
				cout << "You won!" << endl;
				break;
		}
		delete gameOverCode;
	}

}

