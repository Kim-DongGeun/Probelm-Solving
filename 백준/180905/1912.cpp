#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (int i = 2; i <= N; i++)
	{
		if (dp[i - 1] < 0)
			dp[i] = arr[i];
		else
			dp[i] = dp[i-1] + arr[i];
	}

	int ans = -1001;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);
	
	return 0;
}