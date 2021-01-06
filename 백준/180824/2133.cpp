/*
	타일 채우기 문제
	규칙을 정확히 찾지못해서 점화식세우기가 어려웠음
*/
#include <iostream>
using namespace std;

int main()
{
	int N, dp[31] = {0};
	cin >> N;

	dp[0] = 1;
	dp[1] = 0;

	for (int i = 2; i <= N; i+=2)
	{
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2)
			dp[i] += 2 * dp[i - j];
	}

	printf("%d\n", dp[N]);
	return 0;
}