#include <iostream>
#include <queue>
using namespace std;

struct info { int x, y, dir; };
struct source { int x, y, dir, cnt; };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int Change(int dir) {
	switch (dir)
	{
	case 1:
		return 0;
		break;
	case 4:
		return 1;
		break;
	default:
		return dir;
		break;
	}
}

int main() {
	int M, N;
	bool check[101][101][4] = { false, };
	int Map[101][101];
	info start, end;

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];

	cin >> start.y >> start.x >> start.dir;
	cin >> end.y >> end.x >> end.dir;

	start.dir = Change(start.dir);
	end.dir = Change(end.dir);

	queue<source> q;
	q.push({ start.x, start.y, start.dir, 0 });
	check[start.y][start.x][start.dir] = true;
	while (!q.empty()) {
		source cur = q.front();
		q.pop();

		if (cur.x == end.x && cur.y == end.y && cur.dir == end.dir) {
			printf("%d\n", cur.cnt);
			return 0;
		}

		for (int i = 1; i <= 3; i++) { // Go k
			int nx = cur.x + i * dx[cur.dir];
			int ny = cur.y + i * dy[cur.dir];
			
			if (nx <= 0 || ny <= 0 || nx > N || ny > M || check[ny][nx][cur.dir]) continue;
			else if (Map[ny][nx] == 0) {
				check[ny][nx][cur.dir] = true;
				q.push({ nx, ny, cur.dir, cur.cnt + 1 });
			}
			else if (Map[ny][nx] == 1) break;
		}

		int lDir = (cur.dir + 1) % 4;
		int rDir = (cur.dir + 3) % 4;

		if (!check[cur.y][cur.x][lDir]) { // Turn left
			check[cur.y][cur.x][lDir] = true;
			q.push({ cur.x, cur.y, lDir, cur.cnt + 1 });
		}

		if (!check[cur.y][cur.x][rDir]) { // Turn right
			check[cur.y][cur.x][rDir] = true;
			q.push({ cur.x, cur.y, rDir, cur.cnt + 1});
		}

	}
	printf("0\n");
	return 0;
}