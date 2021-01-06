/*
	idea : 길은 모두 있다고 생각하고 벽을 지나갈때에는 카운트를 해준다. bfs로는 왜 안되는지 모르겟다.
*/
#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int check[100][100];

int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

/*struct point {
	int x, y;
};*/

void dfs(int x, int y, int cnt)
{
	check[y][x] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || check[ny][nx] <= cnt) continue;

		if (map[ny][nx] == 0) dfs(nx, ny, cnt);
		else if (map[ny][nx] == 1) dfs(nx, ny, cnt + 1);
	}
}

int main()
{
	
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			check[i][j] = INT16_MAX;
		}

	/*queue<point> q;
	q.push({ 0, 0 });
	check[0][0] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.x == M - 1 && cur.y == N - 1) break;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (ny < 0 || nx < 0 || ny >= N || ny >= M || check[ny][nx] <= check[cur.y][cur.x]) continue;

			if (map[ny][nx] == 0) check[ny][nx] = check[cur.y][cur.x];
			else check[ny][nx] = check[cur.y][cur.x] + 1;
			q.push({ nx, ny });
		}
	}*/

	dfs(0, 0, 0);

	printf("%d\n", check[N - 1][M - 1]);
	return 0;
}