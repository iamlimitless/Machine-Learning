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

/*

Then the learner. Should be it's own class (header + cpp)
	- Should be able to determine the correct strategy in it's guesses (ie always pick heads), should also be able to compute
		"how weighted" the coin is. 

		the more I think about it the simplier this seems. Thats okay we will get our feet wet and then dive deeper into
		the rabit hole
*/