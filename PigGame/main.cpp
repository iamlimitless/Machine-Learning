#include <iostream>
#include "Player.h"
#include "PigGame.h"


int main()
{
	std::cout << "Welcome to this round of pig dice game"  << std::endl;
	PigGame newGame = PigGame(new RollToTwentyPlayer(), new RollIfDownPlayer());
	newGame.PlayGame();
	return 0;
}