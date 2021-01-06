/*
	2xN 타일 채우기 문제
	점화식  f(n) = f(n-1) + f(n-2) (n>2)
*/

#include <iostream>
using namespace std;

int dp[1001] = { 0,1,2 };


int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	printf("%d\n", dp[N]);

	return 0;
}