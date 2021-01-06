/*
	2 x n 타일 2
	점화식 f(n) = f(n-1) + 2f(n-2)
*/
#include <iostream>
using namespace std;

int dp[1001] = { 0,1,3 };

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	printf("%d\n", dp[N]);
	return 0;
}