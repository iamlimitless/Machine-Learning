#include <iostream>
#include "Player.h"
#include "PigGame.h"


int main()
{
	std::cout << "Welcome to this round of pig dice game"  << std::endl;
	PigGame newGame = PigGame(new RollToTwentyPlayer(), new RollToTwentyPlayer());
	int winner;
	for(int i = 0; i < 1000; i++)
	{
		winner = newGame.PlayGame();
	}
	return 0;
}