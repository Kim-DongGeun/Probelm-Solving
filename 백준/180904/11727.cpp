#include <iostream>
using namespace std;

int dp[1001] = { 0,1,3,0 };

//top down
/*int TD(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 3;

	dp[n] = TD(n - 1) + 2 * TD(n - 2);

	return dp[n];
}*/

int main()
{
	
	int N;

	scanf("%d", &N);

	//bottom up
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	printf("%d\n", dp[N]);
	//printf("%d\n", TD(N));
	return 0;
}