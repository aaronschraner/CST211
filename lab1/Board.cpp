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

//TODO: make method comment blocks
void Board::generateNeighbors ()
{
	for(int x=0; x<board.getColumns(); x++)
		for(int y=0; y < board.getRows(); y++)
		{
			short total=0;
			int xd[] = {-1, 0, 1, -1, 1, -1, 0, 1};
			int yd[] = {1, 1, 1, 0, 0, -1, -1, -1 };
			for(int i=0; i<8; i++)
			{
				try
				{
					total += !!board[y+yd[i]][x+xd[i]].hasMine();
				}
				catch (Exception e)
				{
					//do nothing
				}
			}
			board[y][x].setNeighbors(total);
				
		}
}

//TODO: make method comment blocks
void Board::uncoverArea (int x, int y)
{
	int xd[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int yd[] = {1, 1, 1, 0, 0, -1, -1, -1 };
	if(board[y][x].isVisible() == 0)
	{
		board[y][x].setVisible(1);
		if(board[y][x].getNeighbors() == 0)
		{
			for(int i=0; i<8; i++)
			{
				try {
					board[y+yd[i]][x+xd[i]];
				} catch (Exception e) { continue; }
				uncoverArea(x+xd[i], y+yd[i]);
			}
		}
	}

}

//TODO: make method comment blocks
void Board::print ()
{
    //TODO
	cout << "   | ";
	for(int col = 0; col < board.getColumns(); col++)
		cout << setw(2) << left << col << "| ";
	cout << endl << "---+";
	for(int col = 0; col < board.getColumns(); col++)
		cout << "---+" ;
	cout << endl;
	for(int row=0; row < board.getRows(); row++)
	{
		cout << " " << setw(2) << left << row << "| ";
		for(int col = 0; col < board.getColumns(); col++)
			cout << board[row][col] << " | ";
		cout << endl << "---+";
		for(int col = 0; col < board.getColumns(); col++)
			cout << "---+" ;
		cout << endl;
	}
}

//TODO: make method comment blocks
void Board::click (int x, int y)
{
    //TODO
	//board[y][x].setVisible(true);
	if(board[y][x].hasMine())
	{
		cout << "You stepped on a mine! You lose. " << endl;
		for(int r=0; r < board.getRows(); r++)
			for(int c=0; c<board.getColumns(); c++)
				board[r][c].setVisible(1);
		throw Board::GameOver::_LOST;
	}
	uncoverArea(x, y);
	bool coveredLeft = 0;
	for(int r=0; r < board.getRows(); r++)
		for(int c=0; c < board.getColumns(); c++)
			coveredLeft = coveredLeft || (board[r][c].hasMine() != (board[r][c].isVisible()) );
	if(!coveredLeft)
		throw Board::GameOver::_WON;
}

//TODO: make method comment blocks
void Board::flag (int x, int y)
{
	board[y][x].setFlag(!board[y][x].isFlagged());
	board[y][x].setVisible(board[y][x].isFlagged());
	if(getRemainingMines() == 0)
		throw Board::GameOver::_WON;
}

Board::Board(int rows, int cols, int mines):
	rows(rows), cols(cols), mines(mines),
	board(rows, cols)
{
	for(int i=0; i<mines; i++)
	{
		int x, y;
		srand(time(0) + i);
		x=rand() % cols;
		srand(time(0) + mines + i);
		y=rand() % rows;
		if (board[y][x].hasMine())
			mines++;
		else
			board[y][x].setMine(true);
	}
	generateNeighbors();


}

int Board::getRemainingMines()
{
	return mines - getFlaggedMines();
}
int Board::getFlaggedMines()
{
	int fmines = 0;
	for(int r=0; r<board.getRows(); r++)
		for(int c=0; c<board.getColumns(); c++)
			if(board[r][c].isFlagged() && board[r][c].hasMine())
				fmines++;
	return fmines;
}
