#include <iostream>
#include "CoinTosser.h"
#include "WeightedTosser.h"

int main() 
{
	WeightedTosser tosser(70);

	int count = 0;
	while (count != 10000) {
			tosser.Toss();
			count++;
	}

	tosser.PrintResults();
	std::cout << tosser.CalcTossDistribution() << std::endl;
}

/*

Then the learner. Should be it's own class (header + cpp)
	- Should be able to determine the correct strategy in it's guesses (ie always pick heads), should also be able to compute
		"how weighted" the coin is. 

		the more I think about it the simplier this seems. Thats okay we will get our feet wet and then dive deeper into
		the rabit hole
*/