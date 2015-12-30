#include <iostream>
#include "CoinTosser.h"
#include "WeightedTosser.h"
#include "CoinPredictor.h"


int main() 
{
	WeightedTosser tosser(70);
	CoinPredictor predictor(50.0);

	int count = 0;
	while (count != 10000) 
	{
		predictor.VerifyResult( predictor.MakePrediction(),  tosser.Toss());
		count++;
	}

	std::cout << "Tosser Percentage = " << tosser.CalcTossDistribution() << std::endl;
	std::cout << "Correct Guesses = " << predictor.GetNumCorrect() << std::endl;
	std::cout << "Computed Probability = " << predictor.GetProbability() << std::endl;
}
