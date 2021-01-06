#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info
{
	int x;
	int y;
};

int Map[501][501];
int N, M, ans = 0;
int dp[501][501];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int dfs(int x, int y) {

	if (x == 0 && y == 0) {
		return 1;
	}

	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
			if (Map[ny][nx] > Map[y][x]) {
				dp[y][x] += dfs(nx, ny);
			}
			
		}
	}
	return dp[y][x];
}

int main()
{
	scanf_s("%d %d", &M, &N);
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &Map[i][j]);
			dp[i][j] = -1;
		}

	
	/*queue<Info> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		Info temp = q.front();
		q.pop();

		if (temp.x == N - 1 && temp.y == M - 1) {
			ans++;
			continue;
		}

		for (int i = 0; i < edge[temp.y * N + temp.x].size(); i++)
			q.push(edge[temp.y * N + temp.x][i]);
	}
	*/
	printf("%d\n", dfs(N - 1, M - 1));
	
	return 0;
}