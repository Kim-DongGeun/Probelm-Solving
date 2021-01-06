/*
	와인마시기문제
	규칙을 못찾아서 풀이 참조함
*/
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int dp[10001] = { 0 };
	int* arr = new int[N+1];

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i], dp[i - 3] + arr[i] + arr[i - 1]);
	}

	printf("%d\n", dp[N]);
	return 0;
}