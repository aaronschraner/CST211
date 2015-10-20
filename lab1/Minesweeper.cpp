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

//TODO: make method comment blocks
Minesweeper::Minesweeper (int rows, int cols, int mines):
	game(rows, cols, mines), gameOverCode(0)
{
    
}

//TODO: make method comment blocks
bool Minesweeper::gameOver()  const
{
    return !! gameOverCode;
}

//TODO: make method comment blocks
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

//TODO: make method comment blocks
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

void Minesweeper::print()
{
	cout << "Remaining mines: " << game.getRemainingMines() << "   Flagged mines: " << game.getFlaggedMines() << endl;
	game.print();
}
//TODO: make method comment blocks
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
				cout << "You lost! (blown up by mine)" << endl;
				break;
			case Board::GameOver::_WON:
				cout << "You won!" << endl;
				break;
		}
		delete gameOverCode;
	}

}

