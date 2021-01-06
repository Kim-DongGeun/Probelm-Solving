#include <iostream>
using namespace std;

int dp[401][201];


int cal(int N, int M)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == j || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000000;
		}
	}
	return dp[N][M];
}

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);
	//중복조합
	printf("%d\n", cal(N + K - 1, N));
	return 0;
}