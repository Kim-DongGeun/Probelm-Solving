#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321
int N, K;
bool dp[2][500001];

int main() {
	cin >> N >> K;

	memset(dp, false, sizeof(dp));

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	dp[0][N] = true;

	int ans = INF;
	bool found = false;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.second >= 500000 || (K + ((cur.second + 1) * cur.second) / 2) > 500000) break;
		else if (dp[cur.second % 2][K + ((cur.second + 1) * cur.second) / 2]) {
			ans = cur.second;
			found = true;
			break;
		}

		int Mod = (cur.second + 1) % 2;

		if (cur.first > 0 && !dp[Mod][cur.first - 1]) {
			dp[Mod][cur.first - 1] = true;
			q.push({ cur.first - 1, cur.second + 1 });
		}
		if (cur.first < 500000 && !dp[Mod][cur.first + 1]) {
			dp[Mod][cur.first + 1] = true;
			q.push({ cur.first + 1, cur.second + 1 });
		}
		if (cur.first <= 250000 && !dp[Mod][cur.first * 2]) {
			dp[Mod][cur.first * 2] = true;
			q.push({ cur.first * 2, cur.second + 1 });
		}
	}

	printf("%d\n", found ? ans : -1);
	return 0;
}