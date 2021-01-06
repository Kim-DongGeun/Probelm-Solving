#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

struct info {
	int x, y;
};

int N, M, T;
info sword;
int visited[101][101];
int Map[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };



void Build() {
	
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				sword.x = j;
				sword.y = i;
			}
		}
	}
}

int go(int endX, int endY) {
	memset(visited, 0, sizeof(visited));
	queue<info> q;
	q.push({ 1,1});
	visited[1][1] = 1;

	while(!q.empty()) {
		info cur = q.front();
		q.pop();

		if (cur.x == endX && cur.y == endY) {
			return visited[endY][endX] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > M || ny > N) continue;
			else if (Map[ny][nx] != 1 && !visited[ny][nx]) {
				visited[ny][nx] = visited[cur.y][cur.x] + 1;
				q.push({ nx, ny});
			}
		}
	}
	return 10001;
}

int main() {
	Build();
	int minDist = min(go(M, N), go(sword.x, sword.y) + (N - sword.y) + (M - sword.x));
	if (minDist <= T) printf("%d\n", minDist);
	else printf("Fail\n");
	return 0;
}
