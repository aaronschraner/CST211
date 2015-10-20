#include <iostream>
#include "array2D.h"
#include "Board.h"
#include "Minesweeper.h"
#include "Cell.h"
#ifndef MIN
#define MIN(x,y) ( ( (x) < (y) ) ? (x) : (y) )
#endif

using namespace std;

int main()
{

	char difficulty;
	cout << "Enter the difficulty level you want. [b]eginner, [i]ntermediate, [e]xpert\n> ";
	cin >> difficulty;
	Minesweeper* gameptr = 0;
	switch(difficulty)
	{
		//total pleb (me) mode
		case 'p':
			gameptr = new Minesweeper(6, 6, 3);
			break;
		case 'i':
			gameptr = new Minesweeper(16, 16, 40);
			break;
		case 'e':
			gameptr = new Minesweeper(16, 30, 100);
			break;
		default:
			gameptr = new Minesweeper(10, 10, 10);
			break;
	}
	Minesweeper& game = *gameptr;

	while (!game.gameOver())
	{
		game.gameLoop();
	}
	delete &game;
}
