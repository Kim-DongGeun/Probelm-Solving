#include <iostream>
#include <queue>
using namespace std;

struct Data {
	int x;
	int y;
	int z;
	int day;
};

int N, M, H, ans = 0;
int map[101][101][101];

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main()
{
	scanf_s("%d %d %d", &M, &N, &H);

	queue<Data> q;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				scanf_s("%d", &map[i][j][k]);
				if (map[i][j][k] == 1) {
					q.push({ k, j ,i, 0});
				}
			}

	while (!q.empty()) {
		Data temp = q.front();
		q.pop();

		ans = ans < temp.day ? temp.day : ans;

		for (int i = 0; i < 6; i++) {
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			int nz = temp.z + dz[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H)	continue;
			if (map[nz][ny][nx] == 0) {
				q.push({ nx, ny, nz, temp.day + 1 });
				map[nz][ny][nx] = 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}
			}

	printf("%d\n", ans);
	return 0;
}	