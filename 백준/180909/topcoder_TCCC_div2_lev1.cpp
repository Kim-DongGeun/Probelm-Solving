#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2][41] = { 0 };

class BadNeightbors {
public:
	int maxDonations(vector<int> donations)
	{
		dp[0][0] = donations[0];
		dp[0][1] = max(dp[0][0], donations[1]);
		int ans = 0;

		for (int i = 2; i < donations.size() - 1; i++)
		{
			dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + donations[i]);
			ans = max(ans, dp[0][i]);
		}

		dp[1][1] = donations[1];
		dp[1][2] = max(dp[1][1], donations[2]);

		for (int i = 3; i < donations.size(); i++)
		{
			dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + donations[i]);
			ans = max(ans, dp[1][i]);
		}

		return ans;
	}
};

int main()
{
	BadNeightbors bn;
	vector<int> a = { 1,2,3,4,5,1,2,3,4,5 };

	bn.maxDonations(a);

	return 0;
}