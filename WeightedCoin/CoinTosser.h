#ifndef COINTOSSER_H
#define COINTOSSER_H 

#include <vector>

enum Outcome
{
	Heads,
	Tails
};

class CoinTosser
{
public:
	CoinTosser();
	virtual ~CoinTosser();
	virtual int Toss();
	void PrintResults();
	float CalcTossDistribution();
	void IncrementResultsCount(int toss);

private:
	std::vector<int> m_results;
	int m_numHeads;
	int m_numTails;
};


#endif /*COINTOSSER_H*/