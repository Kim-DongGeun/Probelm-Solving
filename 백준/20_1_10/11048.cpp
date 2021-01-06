#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Map[1001][1001];
int dp[1001][1001] = { 0, };

int dfs(int x, int y) {
	if (x == 0 && y == 0) // end condition
		return Map[y][x];
	else if (x < 0 || y < 0)
		return 0;

	if(dp[y][x] == -1)
		dp[y][x] = Map[y][x] + max({ dfs(x - 1, y), dfs(x, y - 1), dfs(x - 1, y - 1) });

	return dp[y][x];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(M - 1, N - 1) << endl;
	return 0;
}