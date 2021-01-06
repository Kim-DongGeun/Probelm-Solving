#include <iostream>
using namespace std;

int main()
{
	int dp[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int N;
	scanf("%d", &N);

	for(int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			dp[j] = (dp[j] + dp[j - 1]) % 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[i]) % 10007;

	printf("%d\n", sum);
	return 0;
}