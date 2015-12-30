#ifndef PIGGAME_H
#define PIGGAME_H

#include "Player.h"

enum Turns 
{
	PLAYER_ONE,
	PLAYER_TWO
};

class PigGame
{
public:
	PigGame(Player* p1, Player* p2);
	~PigGame();
	void PlayGame();

private:
	int RollDice();
	void EndTurn(int turnPoints);
	Player* GetActivePlayer();
	int GetScore();
	int GetOpponentsScore();
	void OutputResults();

	Player* m_p1;
	Player* m_p2;
	int m_p1Score;
	int m_p2Score;
	int m_turn;
};

#endif //PIGGAME_H