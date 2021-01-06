#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];

	for (int i = 2; i <= N; i++)
	{
		int add = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				add = max(add, dp[j]);
			}
		}
		dp[i] = arr[i] + add;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);
	return 0;
}