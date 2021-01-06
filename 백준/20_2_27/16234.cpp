#pragma warning (disable:4996)
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct pos {
	int x, y;
};

int Map[51][51];
int visited[51][51];
pair<int, int> arr[2501];
int N, L, R;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int main() {
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]);
		}

	int ans = 0;
	while (true) {

		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));

		ans++;
		int index = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				queue<pos> q;
				q.push({ j,i });
				visited[i][j] = ++index;
				arr[index].first += Map[i][j];
				arr[index].second++;

				while (!q.empty()) {
					pos cur = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = cur.x + dx[i];
						int ny = cur.y + dy[i];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx]) continue;
						else if (abs(Map[ny][nx] - Map[cur.y][cur.x]) >= L && abs(Map[ny][nx] - Map[cur.y][cur.x]) <= R) {
							visited[ny][nx] = index;
							arr[index].first += Map[ny][nx];
							arr[index].second++;
							q.push({ nx, ny });
						}
					}
				}
			}
		}
		if (index == N * N) break;

		for (int a = 0; a < N; a++) // update
			for (int b = 0; b < N; b++)
				Map[a][b] = arr[visited[a][b]].first / arr[visited[a][b]].second;
	}
	printf("%d\n", ans - 1);
	return 0;
}

