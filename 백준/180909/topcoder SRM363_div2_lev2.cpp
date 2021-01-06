
long dp[51] = { 0 };

class HandShaking {
public:
	long countPerfect(int n)
	{
		dp[0] = 1;
		dp[2] = 1;
		dp[4] = 2;

		for (int i = 6; i <= n; i += 2)
		{
			for (int j = 2; j <= i; j += 2)
			{
				dp[i] += dp[i - j] * dp[j - 2];
			}
		}
		return dp[n];
	}
};

int main()
{
	HandShaking hs;

	hs.countPerfect(8);

	return 0;
}