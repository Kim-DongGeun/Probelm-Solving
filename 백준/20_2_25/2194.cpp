#pragma warning (disable:4996)
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int Map[501][501];
bool visited[501][501];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0, -1, 0 ,1 };

struct pos {
	int x,y,cnt;
};

int main() {
	int N, M, A, B, K;
	scanf("%d %d %d %d %d", &N, &M, &A, &B, &K);

	memset(Map, 0, sizeof(Map));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d %d", &y, &x);
		Map[y][x] = 1;
	}
	pair<int, int> start;
	pair<int, int> end;

	scanf("%d %d", &start.first, &start.second); // first -> y second -> x
	scanf("%d %d", &end.first, &end.second);

	queue<pos> q;
	q.push({ start.second, start.first, 0 });
	visited[start.first][start.second] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.x == end.second && cur.y == end.first) {
			printf("%d\n", cur.cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx <= 0 || nx + B - 1 > M || ny <= 0 || ny + A - 1 > N || visited[ny][nx]) continue; // 맵 벗어나거나 방문했으면
			//else if (Map[ny1][nx1] == 1 || Map[ny1][nx2] == 1 || Map[ny2][nx1] == 1 || Map[ny2][nx2] == 1) continue;
			bool out = false;
			for (int j = 0; j < A; j++)
				for (int k = 0; k < B; k++)
					if (Map[ny + j][nx + k] == 1) out = true; // 장애물이 있으면

			if (!out) {
				visited[ny][nx] = true;
				q.push({ nx, ny, cur.cnt + 1 });
			}
		}
	}
	printf("-1\n");
	return 0;
}