#include <iostream>
using namespace std;

long long dp[101] = { 0,1,1,1,2,2 };

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--) {
		int N;
		scanf("%d", &N);

		for (int i = 6; i <= N; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}