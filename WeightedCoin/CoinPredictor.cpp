#include "CoinTosser.h"
#include "CoinPredictor.h"

CoinPredictor::CoinPredictor(double initProbability) : 
								 m_probability(initProbability),
								 m_numCorrect(0),
								 m_numHeads(0),
								 m_numTosses(0)
{
}

CoinPredictor::~CoinPredictor()
{
}

int CoinPredictor::MakePrediction()
{
	if(m_probability < 50.0) 
	{
		return Heads;
	}
	return Tails;
}

void CoinPredictor::VerifyResult(int prediction, int result)
{
	if(prediction == result) 
	{
		m_numCorrect++;
	}
	UpdateProbability(result);
}

void CoinPredictor::UpdateCounters(int result)
{
	if(result == Heads)
	{
		m_numHeads++;
	}
	m_numTosses++;
}

void CoinPredictor::UpdateProbability(int result)
{
	UpdateCounters(result);
	m_probability = (m_numTosses - m_numHeads) / double(m_numTosses);
}