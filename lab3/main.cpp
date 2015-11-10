#include <iostream>

#include "FreeCell.h"

using namespace std;

CardLocation::Field getField(char c);

int main()
{
	FreeCell game;
	game.initGame();

	while(!game.gameOver())
	{
		CardLocation src;
		CardLocation dest;
		
		game.displayUI();
		char chsrc, chdest;
		cin >> chsrc >> src.index >> chdest >> dest.index;
		src.field = getField(chsrc);
		dest.field = getField(chdest);
		bool success = !game.tryMove(src, dest);
		if(success)
			cout << "Successfully moved card." << endl;
		else
			cout << "Failed to move card." << endl;
	}
}