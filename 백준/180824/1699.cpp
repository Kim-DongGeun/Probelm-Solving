/*
	�������� �� (ex 11 = 3^2 + 1^2 + 1^2)
	1463������ ����ϴ� 1~100000������ �������� �A���߿���
	���� ���� ����Ǽ��� ����
*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, dp[100001] = { 0 };
	cin >> N;

	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j < 317; j++)
		{
			if (i / (int)pow(j, 2) > 0)
				dp[i] = min(dp[i], dp[i - (int)pow(j, 2)] + 1);
		}
	}

	printf("%d\n", dp[N]);
	return 0;
}