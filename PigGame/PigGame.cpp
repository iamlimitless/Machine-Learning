#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "PigGame.h"

PigGame::PigGame(Player* p1, Player* p2) : m_p1(p1),
										 m_p2(p2),
										 m_p1Score(0),
										 m_p2Score(0),
										 m_turn(PLAYER_ONE)
{
	std::srand(std::time(0));
}

PigGame::~PigGame()
{
	delete m_p1;
	delete m_p2;
}

void PigGame::PlayGame()
{
	std::cout << "Game Started" << std::endl;

	Player* activePlayer = GetActivePlayer();
	while(m_p1Score < 100 && m_p2Score < 100)
	{
		int result;
		int turnScore = 0;
		while(activePlayer->DecideToRoll(turnScore, GetScore(), GetOpponentsScore()))
		{
			result = RollDice();
			if(result == 1)
			{
				turnScore = 0;
				break;
			}
			else
			{
				turnScore += result;
			}
		}
		EndTurn(turnScore);
		activePlayer = GetActivePlayer();
		std::cout << "Score is  " << m_p1Score << " " << m_p2Score << std::endl;
	}
	OutputResults();
}

int PigGame::RollDice()
{
	return ((std::rand() % 6) + 1);
}

void PigGame::EndTurn(int turnPoints)
{
	if(m_turn == PLAYER_ONE)
	{
		m_p1Score += turnPoints;
		m_turn = PLAYER_TWO;
	}
	else
	{
		m_p2Score += turnPoints;
		m_turn = PLAYER_ONE;
	}
}

Player* PigGame::GetActivePlayer()
{
	if(m_turn == PLAYER_ONE)
	{
		return m_p1;
	}
	return m_p2;
}

int PigGame::GetScore()
{
	if(m_turn == PLAYER_ONE)
	{
		return m_p1Score;
	}
	return m_p2Score;
}

int PigGame::GetOpponentsScore()
{
	if(m_turn != PLAYER_ONE)
	{
		return m_p1Score;
	}
	return m_p2Score;
}

void PigGame::OutputResults()
{
	std::string winner = "P2";
	if(m_p1Score > m_p2Score)
	{
		winner = "P1"; 
	}
	std::cout << "P1 Score is " << m_p1Score << std::endl;
	std::cout << "P2 Score is " << m_p2Score << std::endl;
	std::cout << "The winner is " << winner << std::endl;
}