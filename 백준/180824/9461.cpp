/*
	파도반 수열
	규칙찾기 쉬웠음
	점화식 f(n) = f(n-1) + f(n-5) (n>6)
*/
#include <iostream>
using namespace std;

int main()
{
	int T, N;
	cin >> T;
	
	long long dp[101] = { 0 };
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;


	while (T--)
	{
		scanf("%d", &N);

		for (int i = 6; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		printf("%lli\n", dp[N]);
	}
	return 0;
}