/*
	계단오르기 문제
	2156문제와 비슷하다
	다른점은 2156은 2개이상을 건너뛸수있지만 이문제는 계단 1개 이하로만
	건너뛸수있다.
*/
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int dp[10001] = { 0 };
	int* arr = new int[N + 1];

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++)
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);

	printf("%d\n", dp[N]);
	return 0;
}