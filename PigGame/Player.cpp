#include "Player.h"

bool RollToTwentyPlayer::DecideToRoll(int turnScore, int currentScore, int opponentScore)
{
	if(turnScore < (100 - currentScore) && turnScore < 20)
	{
		return true;
	}
	return false;
}

bool RollIfDownPlayer::DecideToRoll(int turnScore, int currentScore, int opponentScore)
{
	if((currentScore + turnScore) < opponentScore)
	{
		return true;
	}
	return false;
}