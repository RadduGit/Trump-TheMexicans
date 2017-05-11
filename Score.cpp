class Score
{
	int totalscore;
	int speed = 0;
public:

	void Init()
	{
		totalscore = 0;
	}

	int Actualize()
	{
		totalscore += speed;
	}

	int AddSpeed(int x)
	{
		speed += x;
	}
    
};