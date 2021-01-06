/*
	idea : 처음에는 각 방향에 대해서 전부 나누어서 빨강이 먼저 이동할때
			파랑이 먼저 이동할떄를 나누었지만 실패하고 풀이참조해서
			우선 이동후 이동 방향을 확인해서 좌표를 하나 이동하는 식으로 바꾸었다.
*/
#include <iostream>
#include <queue>
using namespace std;

char Map[11][11];
int bfs_visited[11][11][11][11];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

struct point {
	int depth, rx, ry, bx, by;
};

void move(int &x, int &y, int index) {
	while (1) {
		x += dx[index]; y += dy[index];
		if (Map[y][x] == '#') {
			x -= dx[index]; y -= dy[index];
			break;
		}
		else if (Map[y][x] == 'O')
			break;
	}
}

int main()
{
	int N, M, endx, endy, rx, ry, bx, by;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%1s", &Map[i][j]);
			if (Map[i][j] == 'R') { ry = i; rx = j; }
			else if (Map[i][j] == 'B') { by = i; bx = j; }
			else if (Map[i][j] == 'O') { endy = i; endx = j; }
		}

	int ans = -1;
	queue<point> q;
	q.push({ 0, rx, ry, bx ,by });
	bfs_visited[ry][rx][by][bx] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		
		if (cur.depth > 10) break;
		else if (endy == cur.ry && endx == cur.rx) {
			ans = cur.depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nry = cur.ry;
			int nrx = cur.rx;
			int nby = cur.by;
			int nbx = cur.bx;

			move(nrx, nry, i); move(nbx, nby, i);

			if (nbx == endx && nby == endy) continue;

			if (nby == nry && nbx == nrx) {
				switch (i) {
				case 0: //right
					cur.rx < cur.bx ? nrx-- : nbx--;
					break;
				case 1: //up
					cur.ry < cur.by ? nby++ : nry++;
					break;
				case 2: //left
					cur.rx < cur.bx ? nbx++ : nrx++;
					break;
				case 3: //down
					cur.ry < cur.by ? nry-- : nby--;
					break;
				}
			}

			if (!bfs_visited[nry][nrx][nby][nbx]) { //not visit
				bfs_visited[nry][nrx][nby][nbx] = 1;
				q.push({ cur.depth + 1, nrx, nry, nbx, nby });
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
