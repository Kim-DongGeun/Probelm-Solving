/*
	�������� dp���� ����ġ�� �ִ� �͵��� �����ϸ鼭 �� ���� �ִ븦 ���ϴ� ����
	�ϳ��� ���ذ��鼭 �� ū�Ÿ� ����ȴ�
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100001];
int arr[2][100001];


int main()
{
	int T, N;
	scanf("%d", &T);

	dp[0][0] = 0;
	dp[1][0] = 0;
	
	while (T--)
	{
		scanf("%d", &N);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= N; j++)
				scanf("%d", &arr[i][j]);
		}

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		printf("%d\n", max(dp[0][N], dp[1][N]));
	}


	return 0;
}