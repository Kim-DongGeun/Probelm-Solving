#include <iostream>
using namespace std;

int main()
{
	long long dp[2][91];
	dp[0][1] = 0;
	dp[1][1] = 1;
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	printf("%lld\n", dp[0][N] + dp[1][N]);
	return 0;
}