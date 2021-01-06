/*
	오르막수 (ex) 234458)
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<vector<int>>dp(N, vector<int>(10, 0));
	dp[0] = { 1,1,1,1,1,1,1,1,1,1 };

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[N - 1][i]) % 10007;

	printf("%d\n", sum);
	return 0;
}