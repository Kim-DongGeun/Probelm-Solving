#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100001];

int main()
{
	int T;
	scanf("%d", &T);

	dp[0][0] = 0;
	dp[1][0] = 0;

	while (T--)
	{
		int N;
		scanf("%d", &N);

		//input
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &dp[i][j]);
			}
		}

		//대각선 앞쪽 첫번쨰와 두번째중에 큰것을 선택
		for (int i = 2; i <= N; i++)
		{
			dp[0][i] += max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] += max(dp[0][i - 2], dp[0][i - 1]);
		}
		printf("%d\n", max(dp[0][N], dp[1][N]));
	}
	return 0;
}