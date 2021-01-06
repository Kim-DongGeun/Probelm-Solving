#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001] = { 0 };

int main()
{
	int N;
	scanf("%d", &N);

	dp[1] = 1;

	//N���� ũ�� ���� �������� ���� �ּ��� ��츦 ã�´�.
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j*j <= i; j++)
		{
			if ((i - j*j) >= 0)
				dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}

	printf("%d\n", dp[N]);
	return 0;
}