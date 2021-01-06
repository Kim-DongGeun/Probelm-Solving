/*
	��ܼ��ڹ��� (ex) 45654) 
	n�� �����Ҷ� ��Ģ�� ã�°� �߿�

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	//dp[n][10]�� 0���� �ʱ�ȭ
	vector<vector<int>> dp(N, vector<int>(10, 0));
	dp[0] = { 0,1,1,1,1,1,1,1,1,1 };

	for(int j = 1 ; j< N; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
			{
				dp[j][i] = dp[j - 1][i + 1];
			}
			else if (i == 9)
			{
				dp[j][i] = dp[j - 1][i - 1];
			}
			else
			{
				dp[j][i] = (dp[j - 1][i - 1] + dp[j - 1][i + 1]) % 1000000000;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[N - 1][i]) % 1000000000;

	printf("%d\n", sum );

	return 0;
}