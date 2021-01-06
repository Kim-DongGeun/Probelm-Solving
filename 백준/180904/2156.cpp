#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001] = { 0};
int dp[10001] = { 0 };

int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 1 ; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 1], arr[i] + arr[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i], arr[i] + dp[i - 2]);
	}

	printf("%d\n", dp[N]);

	return 0;
}