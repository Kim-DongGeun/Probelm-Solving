#include <iostream>
using namespace std;


struct info {
	int status; // 1 오른쪽 2 대각선 3 아래쪽
	int x;
	int y;
	int time;
};

int ans = 0;
int N;
int Map[17][17];
//int dp[17][17][3] = { 0, };
const int dx[3][3] = { {1,1,0}, {1,1,0}, {0,1,0} }; // R RD D
const int dy[3][3] = { {0,1,0}, {0,1,1}, {0,1,1} };


void dfs(int x, int y, int dir) {
	if (x == N - 1 && y == N - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[dir][i];
		int ny = y + dy[dir][i];

		if ((nx == x && ny == y) || nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (Map[ny][nx] == 0 && (i == 0 || i == 2))
			dfs(nx, ny, i);
		else if (i == 1 && Map[ny][nx] == 0 && Map[ny - 1][nx] == 0 && Map[ny][nx - 1] == 0)
			dfs(nx, ny, i);
	}
}


int main() {
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &Map[i][j]);
		}
	}

	dfs(1, 0, 0);

	printf("%d\n", ans);
	return 0;
}

