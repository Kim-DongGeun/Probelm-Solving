/*
	이친수 개수찾기
	규칙찾기 쉬웠음
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N; 
	scanf("%d", &N);

	vector<vector<long long>>dp(N, vector<long long>(2, 0));

	dp[0] = { 0,1 };

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; 
		dp[i][1] = dp[i - 1][0];
	}

	long long sum = dp[N - 1][0] + dp[N - 1][1];

	printf("%lli\n", sum);
	return 0;
}