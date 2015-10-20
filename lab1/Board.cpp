/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 17, 2015
 * Last Modified:     October 17, 2015
 * Lab Number:        1
 * Filename:          Board.cpp
 * 
 ********************************************************************************/

#include "Board.h"
#include "array2D.h"
#include "Cell.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/********************************************************************************
 * void generateNeighbors ();
 * 	Purpose: 
 * 		Calculate the number of neighbors for each cell on the board
 * 		(using an array of ints like this was the simplest solution
 * 		I could think of for this problem)
 * 		A "neighbor" is an adjacent cell with a mine in it.
 * 	
 * 	Entry: 
 * 		Nothing
 * 		(but operates on the cells' <neighbors> member variables)
 * 	
 * 	Exit: 
 * 		All elements on the board now have accurate counts for how many
 * 		adjacent mines they have.
 * 	
 ********************************************************************************/
void Board::generateNeighbors ()
{
	//iterate through each cell
	for(int x=0; x<board.getColumns(); x++)
		for(int y=0; y < board.getRows(); y++)
		{
			short total=0;

			//iterate through each cell adjacent to this one
			int xd[] = {-1, 0, 1, -1, 1, -1, 0, 1};
			int yd[] = {1, 1, 1, 0, 0, -1, -1, -1 };
			for(int i=0; i<8; i++)
			{
				//add one to <total> for every adjacent mine
				// (relies on Array2D class for range checking)
				try
				{
					total += !!board[y+yd[i]][x+xd[i]].hasMine();
				}
				catch (Exception e)
				{
					//do nothing
				}
			}
			
			//send the calculated number of neighbors into the current cell
			board[y][x].setNeighbors(total);
				
		}
}

/********************************************************************************
 * void uncoverArea (int x, int y);
 * 	Purpose: 
 * 		Uncover this cell and all the cells around it
 * 		(not just adjacent, recursively uncovers cells in the same way as
 * 		classic minesweeper)
 * 	
 * 	Entry: 
 * 		x: the x coordinate to start uncovering at
 * 		y: the y coordinate to start uncovering at
 * 	
 * 	Exit: 
 * 		Nothing
 * 		(might throw exception if you happen to win)
 * 	
 ********************************************************************************/
void Board::uncoverArea (int x, int y)
{
	//for iterating through adjacent cells
	int xd[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int yd[] = {1, 1, 1, 0, 0, -1, -1, -1 };

	//if this cell hasn't been uncovered yet
	if(board[y][x].isVisible() == 0)
	{
		//uncover it
		board[y][x].setVisible(1);

		//if there are no adjacent bombs
		if(board[y][x].getNeighbors() == 0)
		{
			//call uncoverArea() on every adjacent cell
			// (ignore out-of-range exceptions)
			for(int i=0; i<8; i++)
			{
				//attempt to access this adjacent cell 
				//(will throw exception if it's out of bounds)
				try {
					board[y+yd[i]][x+xd[i]];
				} catch (Exception e) { continue; }

				//call uncoverArea on this adjacent cell
				uncoverArea(x+xd[i], y+yd[i]);
			}
		}
	}

}

/********************************************************************************
 * void print ();
 * 	Purpose: 
 * 		Print the board in stylish ASCII art
 * 		(this version doesn't print remaining and flagged mines)
 * 		(that's Minesweeper::print()'s job)
 * 	
 * 	Entry: 
 * 		only uses the dimensions of the board and operator<<(ostream, Cell)
 * 		(takes no arguments)
 * 	
 * 	Exit: 
 * 		Prints the contents of the minesweeper board in ASCII art
 * 		Cell characters are determined by Cell::charRep().
 * 		Note: the top row and left column are column/row number labels.
 * 		they are NOT the number of neighbors for edge cells.
 * 	
 ********************************************************************************/
void Board::print ()
{
	//first line (column number labels)
	cout << "   | ";
	for(int col = 0; col < board.getColumns(); col++)
		cout << setw(2) << left << col << "| ";

	//second line (just a visual separator)
	cout << endl << "---+";
	for(int col = 0; col < board.getColumns(); col++)
		cout << "---+" ;
	cout << endl;

	//other lines
	//alternates between cell depictions and visual line separators
	for(int row=0; row < board.getRows(); row++)
	{
		//print all the cells in a row separated by pipes and whitespace
		cout << " " << setw(2) << left << row << "| ";
		for(int col = 0; col < board.getColumns(); col++)
			cout << board[row][col] << " | ";
		cout << endl << "---+";

		//print a line separator
		for(int col = 0; col < board.getColumns(); col++)
			cout << "---+" ;
		cout << endl;
	}
}

/********************************************************************************
 * void click (int x, int y);
 * 	Purpose: 
 * 		Click (uncover) the cell at (x, y)
 * 		Throws an exception if you either:
 * 		- win the game by clicking every non-mined cell
 * 		- lose the game by clicking a mined cell
 * 	
 * 	Entry: 
 * 		x: the column of the cell to be clicked
 * 		y: the row of the cell to be clicked
 * 	
 * 	Exit: 
 * 		Can throw GameOver exception
 * 		_WON if you click all non-mined tiles
 * 		_LOST if you click a mine
 * 	
 ********************************************************************************/
void Board::click (int x, int y)
{
	//if the user clicks a mine, tell them they blew up!
	if(board[y][x].hasMine())
	{

		//uncover every cell to show where the user went wrong
		for(int r=0; r < board.getRows(); r++)
			for(int c=0; c<board.getColumns(); c++)
				board[r][c].setVisible(1);

		//throw an exception to let the Minesweeper class know the game has been lost
		throw Board::GameOver::_LOST;
	}

	//try to uncover the cells at and around (x, y)
	uncoverArea(x, y);

	//find if there are any covered spaces left with no mines on them
	//(coveredLeft will be true if any uncovered cell does not have a mine on it)
	bool coveredLeft = 0;
	for(int r=0; r < board.getRows(); r++)
		for(int c=0; c < board.getColumns(); c++)
			coveredLeft = coveredLeft || (!board[r][c].hasMine() && !board[r][c].isVisible() );

	//if all cells except those with mines have been uncovered, user has won the game
	if(!coveredLeft)
		throw Board::GameOver::_WON;
}

/********************************************************************************
 * void flag (int x, int y);
 * 	Purpose: 
 * 		Put a flag on the cell at (x, y)
 * 		Can throw a gameover exception if you flag all of the mines
 * 		on the board.
 * 	
 * 	Entry: 
 * 		x: the x coordinate of the cell to be flagged
 * 		y: the y coordinate of the cell to be flagged
 * 	
 * 	Exit: 
 * 		Nothing (usually)
 * 		but can throw GameOver::_WON if you happen to flag the last mine on
 * 		the board.
 * 	
 ********************************************************************************/
void Board::flag (int x, int y)
{
	//toggle the flag on the cell at (x, y)
	board[y][x].setFlag(!board[y][x].isFlagged());

	//if the cell is now flagged, make it visible
	//otherwise make it covered
	board[y][x].setVisible(board[y][x].isFlagged());

	//if there are no remaining unflagged mines (user has just flagged the last one)
	if(getRemainingMines() == 0)
		throw Board::GameOver::_WON;
}

/********************************************************************************
 * Board(int rows, int cols, int mines);
 * 	Purpose: 
 * 		Board constructor given the number of rows (height)
 * 		and number of columns (width) of the board,
 * 		and also the number of mines to randomly disperse through the board
 * 	
 * 	Entry: 
 * 		int rows: the number of rows to create the board with
 * 		int cols : the number of columns to create the board with
 * 		int mines: the number of mines to randomly place on the board
 * 	
 * 	Exit: 
 * 		Constructs the board with requested dimensions and randomly places
 * 		the mines
 * 		BUG/WARNING: can re-create the same mine pattern multiple times if
 * 		constructor is run more than once within <mines> seconds
 * 	
 ********************************************************************************/
Board::Board(int rows, int cols, int mines):
	//initialize the number of rows, columns, and mines in the board
	rows(rows), cols(cols), mines(mines), 

	//construct the Array2D of Cells with the requested dimensions
	board(rows, cols)
{
	// randomly place <mines> mines on the board
	for(int i=0; i<mines; i++)
	{
		//get random coordinates
		int x, y;
		srand(time(0) + i);
		x=rand() % cols;
		srand(time(0) + mines + i);
		y=rand() % rows;

		//if that cell already has a mine, just place more instead. 
		if (board[y][x].hasMine())
			mines++;

		//otherwise, place the mine. 
		else
			board[y][x].setMine(true);
	}

	//calculate how many neighbors each cell has and store them in the contained Array2D<Cell>
	generateNeighbors();


}

/********************************************************************************
 * int getRemainingMines();
 * 	Purpose: 
 * 		Find the number of mines on the board that have yet to be flagged
 * 		This can also be used for cheating but again is very impractical
 * 		for that purpose.
 * 		(depends on getFlaggedMines())
 * 	
 * 	Entry: 
 * 		Nothing (but uses getFlaggedMines and the initial mine count)
 * 	
 * 	Exit: 
 * 		Returns the number of mines that haven't been flagged yet
 * 	
 ********************************************************************************/
int Board::getRemainingMines()
{
	return mines - getFlaggedMines();
}


/********************************************************************************
 * int getFlaggedMines();
 * 	Purpose: 
 * 		Get the number of correctly flagged mines on the board
 * 		This can technically be used to cheat, but it would be extremely
 * 		time consuming to use it for that (especially on expert mode)
 * 		
 * 		A "correctly flagged" mine is a cell that has a mine in it and is flagged.
 * 	
 * 	Entry: 
 * 		no arguments
 * 	
 * 	Exit: 
 * 		Returns the total number of correctly flagged mines
 * 		(iterates through entire board to figure that out)
 * 	
 ********************************************************************************/
int Board::getFlaggedMines()
{
	//iterate through the array, counting the number of cells that are both 
	//flagged and mined (contain mines)
	int fmines = 0;
	for ( int r = 0; r < board.getRows(); r++ )
		for ( int c = 0; c < board.getColumns(); c++ )
			if ( board[r][c].isFlagged() && board[r][c].hasMine() )
				fmines++;
	return fmines;
}
