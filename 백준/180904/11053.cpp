#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
	int N, ans = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		dp[i]++;
	}

	// dp[n]�� n�������� ����� �����ϴ� ������ ����
	// n=1���� ���ϸ鼭 �ö󰡸� Ǯ�̰���
	for (int i = 1; i <= N; i++)
	{
		int add = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				add = max(add, dp[j]);
			}
		}
		dp[i] += add;
	}

	for (int i = 1; i <= 1000; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);
	return 0;
}