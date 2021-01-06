#include <iostream>
#include <algorithm>
using namespace std;

int map[3][1001];
int dp[3][1001];

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &map[0][i], &map[1][i], &map[2][i]);
		dp[0][i] = 0;
		dp[1][i] = 0;
		dp[2][i] = 0;
	}

	dp[0][1] = map[0][1];
	dp[1][1] = map[1][1];
	dp[2][1] = map[2][1];

	for (int i = 2; i <= N; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + map[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + map[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + map[2][i];
	}

	int ans = min(dp[0][N], min(dp[1][N], dp[2][N]));
	printf("%d\n", ans);
	return 0;
}