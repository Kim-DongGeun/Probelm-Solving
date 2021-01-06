#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int check[101][101];
int N;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

/*void dfs(int x, int y) {
	
	if (x == N-1 && y == N-1) {
		ans = ans < check[y][x] ? ans : check[y][x];
		return;
	}

	for (int index = 0; index < 4; index++) {
		int nx = x + dx[index];
		int ny = y + dy[index];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || check[ny][nx]) continue;

		check[ny][nx] += map[ny][nx] + check[y][x];
		dfs(nx, ny);
		check[ny][nx] = 0;
	}
}*/

struct point {
	int x, y;
};


int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
				check[i][j] = INT32_MAX;
			}
		
		queue<point> q;
		q.push({ 0,0 });
		check[0][0] = 1;
		while (!q.empty()) {
			point cur = q.front();
			int x = cur.x;
			int y = cur.y;
			q.pop();

			for (int i = 0; i < 4; i++) {

				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

				if (check[ny][nx] <= check[y][x] + map[ny][nx]) continue;

				check[ny][nx] = check[y][x] + map[ny][nx];
				q.push({ nx, ny });
			}
		}

		printf("#%d %d\n", t, check[N-1][N-1] -1);
	}
	return 0;
}