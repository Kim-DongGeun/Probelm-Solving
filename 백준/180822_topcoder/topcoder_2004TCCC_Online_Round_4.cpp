// 도시 기부금 문제 (아무리 봐도 이해가 안감)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BadNeightbors
{
public:
	int maxDonations(vector<int> donations)
	{
		int ans = 0;

		int N = donations.size();
		int* dp = new int[N];

		for (int i = 0; i < N-1; i++)
		{
			dp[i] = donations[i];
			if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
			if (i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i]);
			ans = max(ans, dp[i]);
		}

		for (int i = 0; i < N - 1; i++)
		{
			dp[i] = donations[i + 1];
			if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
			if (i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i + 1]);
			ans = max(ans, dp[i]);
		}

		delete[] dp;
		return ans;
	}
};


int main()
{
	return 0;
}