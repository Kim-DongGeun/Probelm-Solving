#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int n, k;

int dp[1001][1001];

int dfs(int N, int K) {
	if (N == K || K == 0) return 1;
	else if (K == 1) return N;

	int& ret = dp[N][K];
	if (ret != 0) return ret;

	ret = (ret + (dfs(N - 1, K) + dfs(N - 1, K - 1))) % 10007;

	return ret;
}

int main() {
	cin >> n >> k;
	cout << dfs(n, k);
	return 0;
}

