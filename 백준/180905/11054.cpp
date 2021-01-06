#include <iostream>
#include <algorithm>
using namespace std;

int dec_dp[1001] = { 0 };
int arr[1001];
int inc_dp[1001] = { 0 };

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		inc_dp[i]++;
		dec_dp[i]++;
	}
	//증가하는 가장 긴 수열
	for (int i = 1; i <= N; i++)
	{
		int add = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				add = max(add, inc_dp[j]);
			}
		}
		inc_dp[i] += add;
	}

	//감소하는 가장 긴 수열
	for (int i = N; i >= 1; i--)
	{
		int add = 0;
		for (int j = N; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				add = max(add, dec_dp[j]);
			}
		}
		dec_dp[i] += add;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dec_dp[i] + inc_dp[i]);

	printf("%d\n", ans-1);
	return 0;
}