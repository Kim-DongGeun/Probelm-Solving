/*
	제곱수의 합 (ex 11 = 3^2 + 1^2 + 1^2)
	1463문제와 비슷하다 1~100000사이의 제곱수로 뺸것중에서
	가장 작은 경우의수를 선택
*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, dp[100001] = { 0 };
	cin >> N;

	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j < 317; j++)
		{
			if (i / (int)pow(j, 2) > 0)
				dp[i] = min(dp[i], dp[i - (int)pow(j, 2)] + 1);
		}
	}

	printf("%d\n", dp[N]);
	return 0;
}