#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[1001];
	int map[1001];
	int N;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &map[i]);
	}

	dp[1] = map[1];
	dp[2] = max(2 * map[1], map[2]);

	for (int i = 3; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
		dp[i] = max(map[i], dp[i]);
	}
	printf("%d\n", dp[N]);
	return 0;
}