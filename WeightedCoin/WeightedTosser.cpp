#include "WeightedTosser.h"
#include <cstdlib>

WeightedTosser::WeightedTosser(double percentHeads) : 
	m_percentHeads(percentHeads)
{
}

WeightedTosser::~WeightedTosser() 
{
}

int WeightedTosser::Toss()
{
	int precision = 1000;
	int fairToss = rand() % precision;
	double headsThreshold = (m_percentHeads / 100) * precision;
	if (fairToss < headsThreshold) 
	{
		IncrementResultsCount(Heads);
		return Heads;
	}
	IncrementResultsCount(Tails);
	return Tails;
}