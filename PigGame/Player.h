#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player() {}
	virtual ~Player() {}
	virtual bool DecideToRoll(int turnScore, int currentScore, int opponentScore) = 0;
};

class RollToTwentyPlayer : public Player
{
public:
	RollToTwentyPlayer(){}
	~RollToTwentyPlayer() {}
	virtual bool DecideToRoll(int turnScore, int currentScore, int opponentScore);
};

class RollIfDownPlayer : public Player
{
public:
	RollIfDownPlayer(){}
	~RollIfDownPlayer() {}
	virtual bool DecideToRoll(int turnScore, int currentScore, int opponentScore);
};

class OptimalPlayer : public Player
{
public:
	OptimalPlayer(){}
	~OptimalPlayer() {}
	virtual bool DecideToRoll(int turnScore, int currentScore, int opponentScore);
};

#endif //PLAYER_H