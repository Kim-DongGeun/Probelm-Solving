#include <iostream>
using namespace std;

int main()
{
	int dp[11] = { 0 };
	int save[11] = { 0 };

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= 9; i++)
		save[i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 8; j++)
			dp[j] = (save[j - 1] + save[j + 1]) % 1000000000;
		dp[0] = save[1];
		dp[9] = save[8];

		for (int j = 0; j <= 9; j++)
			save[j] = dp[j];
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = (ans + save[i]) % 1000000000;
	}
	printf("%d\n", ans);
	return 0;
}