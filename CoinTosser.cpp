#include <iostream>
#include <cstdlib>
#include "CoinTosser.h"

CoinTosser::CoinTosser() : m_numHeads(0),
						   m_numTails(0)
{
}

CoinTosser::~CoinTosser() 
{
	m_results.clear();
}

int CoinTosser::Toss()
{
	int toss = rand() % 2;
	IncrementResultsCount(toss);
}

void CoinTosser::IncrementResultsCount(int toss) 
{
	m_results.push_back(toss);
	if (toss == Heads) 
	{
		m_numHeads++ ;
	} 
	else 
	{
		m_numTails++;
	}
}

void CoinTosser::PrintResults()
{
	for (int i : m_results) 
	{
		std::cout << i << std::endl;
	}
}

float CoinTosser::CalcTossDistribution() 
{
	float total = m_numHeads + m_numTails;
	return (m_numHeads / total) * 100;
}

