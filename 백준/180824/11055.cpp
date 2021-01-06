/*
	���� ����ū �����ϴ� ��������(LIS)
	���� ������ dp�����̹Ƿ� �����־߰ڴ�
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, answer = 0;
	cin >> N;

	int arr[1001] = { 0 };
	int dp[1001] = { 0 };

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		answer = max(answer, dp[i]);
	}

	printf("%d\n", answer);
	return 0;
}