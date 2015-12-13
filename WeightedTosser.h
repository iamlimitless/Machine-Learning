#ifndef WEIGHTEDTOSSER_H
#define WEIGHTEDTOSSER_H 

#include "CoinTosser.h"

class WeightedTosser : public CoinTosser
{
public:
	WeightedTosser(double percentHeads);
	virtual ~WeightedTosser();
	virtual int Toss();

private:
	double m_percentHeads;
};

#endif /*WEIGHTEDTOSSER_H*/