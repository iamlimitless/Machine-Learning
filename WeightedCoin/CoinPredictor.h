
class CoinPredictor
{
public:
	CoinPredictor(double initProbability);
	~CoinPredictor();
	int MakePrediction();
	void VerifyResult(int prediction, int result);
	int GetNumTosses() { return m_numTosses; }
	int GetNumCorrect() { return m_numCorrect; }
	double GetProbability() { return m_probability*100; }

private:
	void UpdateProbability(int result);
	void UpdateCounters(int result);
	double m_probability;
	int m_numCorrect;
	int m_numHeads;
	int m_numTosses;
};