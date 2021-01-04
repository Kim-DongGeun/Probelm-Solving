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
int n, arr[501];
int dp[501][501] = { 0, };


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (i) arr[i] += arr[i - 1];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n - i; j++) {
				int r = j;
				int c = i + j;
				if (r == c) dp[r][c] = 0;
				else {
					dp[r][c] = INT32_MAX;
					for (int k = r; k < c; k++) {
						dp[r][c] = min(dp[r][c], dp[r][k] + dp[k + 1][c] + arr[c] - arr[r-1]);
					}
				}
			}
		}
		cout << dp[0][n - 1] << '\n';
	}

	return 0;
}