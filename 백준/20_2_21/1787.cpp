#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define INF 987654321

vector<int> getPi(string p)
{
	int m = (int)p.size();
	int j = 0;

	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> pi;
vector<int> dp;

int dfs(int cur) {
	if (cur < 0 || pi[cur] == 0) return INF;

	int& ret = dp[cur];

	if (ret != -1) return ret;

	return ret = min(pi[cur], dfs(pi[cur] - 1));
}

int main() {
	int N;
	string input;
	cin >> N >> input;

	pi = getPi(input);

	int ans = 0;
	dp.resize(N);
	fill(dp.begin(), dp.end(), -1);

	for (int i = 0; i < pi.size(); i++) {
		
		int ret = dfs(i);

		if (ret != INF)
			ans += (i - ret + 1);
	}

	cout << ans << '\n';
	return 0;
}