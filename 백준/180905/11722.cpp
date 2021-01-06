#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = { 0 };
int arr[1001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		dp[i]++;
	}

	for (int i = N; i >= 1; i--)
	{
		int add = 0;
		for (int j = N; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				add = max(add, dp[j]);
			}
		}
		dp[i] += add;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);
	return 0;
}