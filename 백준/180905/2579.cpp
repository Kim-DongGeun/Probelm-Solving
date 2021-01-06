#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}

	printf("%d\n", dp[N]);
	return 0;

}