#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Data { int x, y; };
struct info { int x, y, cnt, crash; };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int main() {
	int N, M;
	int Map[1001][1001];
	vector<Data> wall;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &Map[i][j]);
			if (Map[i][j] == 1) wall.push_back({ j,i });
		}

	bool success = false;
	int ans = INT32_MAX;
	bool check[2][1001][1001] = { false, };
	queue<info> q;
	q.push({ 0,0,1,1 });
	check[1][0][0] = true;
	while (!q.empty()) {
		info cur = q.front();
		q.pop();

		if (cur.x == M - 1 && cur.y == N - 1) {
			ans = ans > cur.cnt ? cur.cnt : ans;
			success = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + cur.x;
			int ny = dy[i] + cur.y;

			if (nx < 0 || ny < 0 || nx >= M || ny >= N || check[cur.crash][ny][nx]) continue;

			else if (Map[ny][nx] == 1) { // if wall
				if (cur.crash == 1) {
					check[cur.crash][ny][nx] = true;
					q.push({ nx, ny, cur.cnt + 1, 0 });
				}
			}
			else if (Map[ny][nx] == 0) { // if not wall
				check[cur.crash][ny][nx] = true;
				q.push({ nx, ny, cur.cnt + 1, cur.crash });
			}

		}
	}
	if (success)
		printf("%d\n", ans);
	else
		printf("-1\n");

	return 0;
}